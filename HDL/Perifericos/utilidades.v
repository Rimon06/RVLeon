
module asciiTo8x8_( 
  input  [ 7: 0] character,
  output [63: 0] letra
  );
  `include "font8x8.vh"
  
  reg [63:0] letra;
  always @(*) begin
    case (character)
      16: letra = _cRISCV;
      17: letra = _cRISCV_;

      " ": letra = _cSPACE; // space
      "!": letra = _cEXCL;
     "\"": letra = _cQUOT;
      "#": letra = _cNUMBER;
      "$": letra = _cDOLLAR;
      "%": letra = _cPERCNT;
      "&": letra = _cAMP;
      "'": letra = _cAPOS;
      "(": letra = _cLBR;
      ")": letra = _cRBR;
      "*": letra = _cAST;
      "+": letra = _cPLUS;
      ",": letra = _cCOMMA;
      "-": letra = _cMINUS;
      ".": letra = _cDOT;
      "/": letra = _cSLASH;

      "0": letra = _c0;
      "1": letra = _c1;
      "2": letra = _c2;
      "3": letra = _c3;
      "4": letra = _c4;
      "5": letra = _c5;
      "6": letra = _c6;
      "7": letra = _c7;
      "8": letra = _c8;
      "9": letra = _c9;

      ":": letra = _cCOLON;
      ";": letra = _cSEMIC;
      "<": letra = _cLT;
      "=": letra = _cEQ;
      ">": letra = _cGT;
      "?": letra = _cQUEST;
      "@": letra = _cAT;

      "A": letra = _cA;
      "B": letra = _cB;
      "C": letra = _cC;
      "D": letra = _cD;
      "E": letra = _cE;
      "F": letra = _cF;
      "G": letra = _cG;
      "H": letra = _cH;
      "I": letra = _cI;
      "J": letra = _cJ;
      "K": letra = _cK;
      "L": letra = _cL;
      "M": letra = _cM;
      "N": letra = _cN;
      "O": letra = _cO;
      "P": letra = _cP;
      "Q": letra = _cQ;
      "R": letra = _cR;
      "S": letra = _cS;
      "T": letra = _cT;
      "U": letra = _cU;
      "V": letra = _cV;
      "W": letra = _cW;
      "X": letra = _cX;
      "Y": letra = _cY;
      "Z": letra = _cZ;

      "[": letra = _cLSQBR;
     "\\": letra = _cBKSLASH;
      "]": letra = _cRSQBR;
      "^": letra = _cHAT;
      "_": letra = _cLOWBAR;
      "`": letra = _cGRAVE;

      "a": letra = _cA_;
      "b": letra = _cB_;
      "c": letra = _cC_;
      "d": letra = _cD_;
      "e": letra = _cE_;
      "f": letra = _cF_;
      "g": letra = _cG_;
      "h": letra = _cH_;
      "i": letra = _cI_;
      "j": letra = _cJ_;
      "k": letra = _cK_;
      "l": letra = _cL_;
      "m": letra = _cM_;
      "n": letra = _cN_;
      "o": letra = _cO_;
      "p": letra = _cP_;
      "q": letra = _cQ_;
      "r": letra = _cR_;
      "s": letra = _cS_;
      "t": letra = _cT_;
      "u": letra = _cU_;
      "v": letra = _cV_;
      "w": letra = _cW_;
      "x": letra = _cX_;
      "y": letra = _cY_;
      "z": letra = _cZ_;

      "{": letra = _cLCUBR;
      "|": letra = _cVBAR ;
      "}": letra = _cRCUBR;
      "~": letra = _cTILDE;
      default:
        letra = _cSPACE; 
    endcase

  end
endmodule