import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
public class DumpFunc extends GhidraScript {
  public void run() throws Exception {
    String[] a = getScriptArgs();
    Address ep = toAddr(Long.parseLong(a[0],16));
    Function f = getFunctionAt(ep);
    PrintWriter out = new PrintWriter(new FileWriter(a[1]));
    Listing L = currentProgram.getListing();
    InstructionIterator it = L.getInstructions(f.getBody(), true);
    while (it.hasNext()) {
      Instruction ins = it.next();
      StringBuilder sb = new StringBuilder();
      sb.append(ins.getAddress()).append('\t').append(ins.toString());
      for (Reference r : ins.getReferencesFrom()) {
        Address to = r.getToAddress();
        Data d = L.getDataAt(to);
        if (r.getReferenceType().isCall()) {
          Function cf = getFunctionAt(to);
          sb.append("\tCALL ").append(cf != null ? cf.getName(true) : to.toString());
        } else if (d != null && d.hasStringValue()) {
          sb.append("\tSTR ").append(d.getValue());
        } else if (d != null) {
          // pointer to string?
          Object v = d.getValue();
          if (v instanceof Address) {
            Data d2 = L.getDataAt((Address)v);
            if (d2 != null && d2.hasStringValue()) sb.append("\tPSTR ").append(d2.getValue());
            else sb.append("\tPTR ").append(v);
          } else if (v instanceof Scalar) sb.append("\tLIT ").append(((Scalar)v).getValue());
        }
      }
      out.println(sb);
    }
    out.close();
  }
}
