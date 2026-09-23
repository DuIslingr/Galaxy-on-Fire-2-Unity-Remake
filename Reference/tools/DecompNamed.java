import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.regex.*;
public class DecompNamed extends GhidraScript {
  public void run() throws Exception {
    String[] a = getScriptArgs();
    Pattern p = Pattern.compile(a[0]);
    PrintWriter out = new PrintWriter(new FileWriter(a[1]));
    DecompInterface d = new DecompInterface(); d.openProgram(currentProgram);
    for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
      String n = f.getName(true);
      if (!p.matcher(n).find()) continue;
      DecompileResults r = d.decompileFunction(f, 120, monitor);
      out.println("// ===== " + n + " @ " + f.getEntryPoint());
      out.println(r.decompileCompleted() ? r.getDecompiledFunction().getC() : "// failed");
    }
    out.close();
  }
}
