import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;
public class DecompAll extends GhidraScript {
  public void run() throws Exception {
    String outDir = getScriptArgs()[0];
    new File(outDir).mkdirs();
    DecompInterface d = new DecompInterface();
    DecompileOptions o = new DecompileOptions(); d.setOptions(o);
    d.openProgram(currentProgram);
    PrintWriter idx = new PrintWriter(new FileWriter(outDir + "/_functions.tsv"));
    PrintWriter out = new PrintWriter(new FileWriter(outDir + "/_all.c"));
    int n=0;
    for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
      if (f.isThunk() || f.isExternal()) continue;
      if (monitor.isCancelled()) break;
      String name = f.getName(true);
      long size = f.getBody().getNumAddresses();
      DecompileResults r = d.decompileFunction(f, 180, monitor);
      String c = (r != null && r.decompileCompleted()) ? r.getDecompiledFunction().getC() : "/* decompile failed: " + (r==null?"null":r.getErrorMessage()) + " */\n";
      out.println("//@@FUNC\t" + name + "\t" + f.getEntryPoint() + "\t" + size);
      out.println(c);
      idx.println(name + "\t" + f.getEntryPoint() + "\t" + size + "\t" + (r!=null && r.decompileCompleted()));
      if (++n % 250 == 0) { println("done " + n); out.flush(); idx.flush(); }
    }
    out.close(); idx.close();
    println("TOTAL " + n);
  }
}
