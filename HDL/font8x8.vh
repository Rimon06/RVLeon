/*
 * 8x8 monochrome bitmap fonts for rendering
 * Author: Daniel Hepper <daniel@hepper.net>
 *
 * License: Public Domain
 *
 * Based on:
 * // Summary: font8x8.h
 * // 8x8 monochrome bitmap fonts for rendering
 * //
 * // Author:
 * //     Marcel Sondaar
 * //     International Business Machines (public domain VGA fonts)
 * //
 * // License:
 * //     Public Domain
 *
 * Fetched from: http://dimensionalrift.homelinux.net/combuster/mos3/?p=viewsource&file=/modules/gfx/font8_8.asm
 * https://www.ascii-code.com/
 */

// Contains an 8x8 font map for unicode points U+0000 - U+007F (basic latin)
// Desde U+0000 hasta U+001F (Y U+007F) no se definen valores, valen 0
parameter _cSPACE = 64'h00_00_00_00_00_00_00_00;   // U+0020 (space)
parameter _cEXCL  = 64'h18_3C_3C_18_18_00_18_00;   // U+0021 (!)
parameter _cQUOT  = 64'h36_36_00_00_00_00_00_00;   // U+0022 (")
parameter _cNUMBER  = 64'h36_36_7F_36_7F_36_36_00; // U+0023 (#)
parameter _cDOLLAR  = 64'h0C_3E_03_1E_30_1F_0C_00; // U+0024 ($)
parameter _cPERCNT  = 64'h00_63_33_18_0C_66_63_00; // U+0025 (%)
parameter _cAMP   = 64'h1C_36_1C_6E_3B_33_6E_00;   // U+0026 (&)
parameter _cAPOS  = 64'h06_06_03_00_00_00_00_00;   // U+0027 (')
parameter _cLBR   = 64'h18_0C_06_06_06_0C_18_00;   // U+0028 (()
parameter _cRBR   = 64'h06_0C_18_18_18_0C_06_00;   // U+0029 ())
parameter _cAST   = 64'h00_66_3C_FF_3C_66_00_00;   // U+002A (*)
parameter _cPLUS  = 64'h00_0C_0C_3F_0C_0C_00_00;   // U+002B (+)
parameter _cCOMMA = 64'h00_00_00_00_00_0C_0C_06;   // U+002C (,)
parameter _cMINUS = 64'h00_00_00_3F_00_00_00_00;   // U+002D (-)
parameter _cDOT   = 64'h00_00_00_00_00_0C_0C_00;   // U+002E (.)
parameter _cSLASH = 64'h60_30_18_0C_06_03_01_00;   // U+002F (/)

parameter _c0     = 64'h3E_63_73_7B_6F_67_3E_00;   // U+0030 (0)
parameter _c1     = 64'h0C_0E_0C_0C_0C_0C_3F_00;   // U+0031 (1)
parameter _c2     = 64'h1E_33_30_1C_06_33_3F_00;   // U+0032 (2)
parameter _c3     = 64'h1E_33_30_1C_30_33_1E_00;   // U+0033 (3)
parameter _c4     = 64'h38_3C_36_33_7F_30_78_00;   // U+0034 (4)
parameter _c5     = 64'h3F_03_1F_30_30_33_1E_00;   // U+0035 (5)
parameter _c6     = 64'h1C_06_03_1F_33_33_1E_00;   // U+0036 (6)
parameter _c7     = 64'h3F_33_30_18_0C_0C_0C_00;   // U+0037 (7)
parameter _c8     = 64'h1E_33_33_1E_33_33_1E_00;   // U+0038 (8)
parameter _c9     = 64'h1E_33_33_3E_30_18_0E_00;   // U+0039 (9)

parameter _cCOLON = 64'h00_0C_0C_00_00_0C_0C_00;   // U+003A (:)
parameter _cSEMIC = 64'h00_0C_0C_00_00_0C_0C_06;   // U+003B (;)
parameter _cLT    = 64'h18_0C_06_03_06_0C_18_00;   // U+003C (<)
parameter _cEQ    = 64'h00_00_3F_00_00_3F_00_00;   // U+003D (=)
parameter _cGT    = 64'h06_0C_18_30_18_0C_06_00;   // U+003E (>)
parameter _cQUEST = 64'h1E_33_30_18_0C_00_0C_00;   // U+003F (?)
parameter _cAT    = 64'h3E_63_7B_7B_7B_03_1E_00;   // U+0040 (@)

parameter _cA     = 64'h0C_1E_33_33_3F_33_33_00;   // U+0041 (A)
parameter _cB     = 64'h3F_66_66_3E_66_66_3F_00;   // U+0042 (B)
parameter _cC     = 64'h3C_66_03_03_03_66_3C_00;   // U+0043 (C)
parameter _cD     = 64'h1F_36_66_66_66_36_1F_00;   // U+0044 (D)
parameter _cE     = 64'h7F_46_16_1E_16_46_7F_00;   // U+0045 (E)
parameter _cF     = 64'h7F_46_16_1E_16_06_0F_00;   // U+0046 (F)
parameter _cG     = 64'h3C_66_03_03_73_66_7C_00;   // U+0047 (G)
parameter _cH     = 64'h33_33_33_3F_33_33_33_00;   // U+0048 (H)
parameter _cI     = 64'h1E_0C_0C_0C_0C_0C_1E_00;   // U+0049 (I)
parameter _cJ     = 64'h78_30_30_30_33_33_1E_00;   // U+004A (J)
parameter _cK     = 64'h67_66_36_1E_36_66_67_00;   // U+004B (K)
parameter _cL     = 64'h0F_06_06_06_46_66_7F_00;   // U+004C (L)
parameter _cM     = 64'h63_77_7F_7F_6B_63_63_00;   // U+004D (M)
parameter _cN     = 64'h63_67_6F_7B_73_63_63_00;   // U+004E (N)
parameter _cO     = 64'h1C_36_63_63_63_36_1C_00;   // U+004F (O)
parameter _cP     = 64'h3F_66_66_3E_06_06_0F_00;   // U+0050 (P)
parameter _cQ     = 64'h1E_33_33_33_3B_1E_38_00;   // U+0051 (Q)
parameter _cR     = 64'h3F_66_66_3E_36_66_67_00;   // U+0052 (R)
parameter _cS     = 64'h1E_33_07_0E_38_33_1E_00;   // U+0053 (S)
parameter _cT     = 64'h3F_2D_0C_0C_0C_0C_1E_00;   // U+0054 (T)
parameter _cU     = 64'h33_33_33_33_33_33_3F_00;   // U+0055 (U)
parameter _cV     = 64'h33_33_33_33_33_1E_0C_00;   // U+0056 (V)
parameter _cW     = 64'h63_63_63_6B_7F_77_63_00;   // U+0057 (W)
parameter _cX     = 64'h63_63_36_1C_1C_36_63_00;   // U+0058 (X)
parameter _cY     = 64'h33_33_33_1E_0C_0C_1E_00;   // U+0059 (Y)
parameter _cZ     = 64'h7F_63_31_18_4C_66_7F_00;   // U+005A (Z)

parameter _cLSQBR = 64'h1E_06_06_06_06_06_1E_00;   // U+005B ([)
parameter _cBKSLASH = 64'h03_06_0C_18_30_60_40_00; // U+005C (\)
parameter _cRSQBR = 64'h1E_18_18_18_18_18_1E_00;   // U+005D (])
parameter _cHAT   = 64'h08_1C_36_63_00_00_00_00;   // U+005E (^)
parameter _cLOWBAR  = 64'h00_00_00_00_00_00_00_FF; // U+005F (_)
parameter _cGRAVE = 64'h0C_0C_18_00_00_00_00_00;   // U+0060   (`)

parameter _cA_    = 64'h00_00_1E_30_3E_33_6E_00;   // U+0061 (a)
parameter _cB_    = 64'h07_06_06_3E_66_66_3B_00;   // U+0062 (b)
parameter _cC_    = 64'h00_00_1E_33_03_33_1E_00;   // U+0063 (c)
parameter _cD_    = 64'h38_30_30_3e_33_33_6E_00;   // U+0064 (d)
parameter _cE_    = 64'h00_00_1E_33_3f_03_1E_00;   // U+0065 (e)
parameter _cF_    = 64'h1C_36_06_0f_06_06_0F_00;   // U+0066 (f)
parameter _cG_    = 64'h00_00_6E_33_33_3E_30_1F;   // U+0067 (g)
parameter _cH_    = 64'h07_06_36_6E_66_66_67_00;   // U+0068 (h)
parameter _cI_    = 64'h0C_00_0E_0C_0C_0C_1E_00;   // U+0069 (i)
parameter _cJ_    = 64'h30_00_30_30_30_33_33_1E;   // U+006A (j)
parameter _cK_    = 64'h07_06_66_36_1E_36_67_00;   // U+006B (k)
parameter _cL_    = 64'h0E_0C_0C_0C_0C_0C_1E_00;   // U+006C (l)
parameter _cM_    = 64'h00_00_33_7F_7F_6B_63_00;   // U+006D (m)
parameter _cN_    = 64'h00_00_1F_33_33_33_33_00;   // U+006E (n)
parameter _cO_    = 64'h00_00_1E_33_33_33_1E_00;   // U+006F (o)
parameter _cP_    = 64'h00_00_3B_66_66_3E_06_0F;   // U+0070 (p)
parameter _cQ_    = 64'h00_00_6E_33_33_3E_30_78;   // U+0071 (q)
parameter _cR_    = 64'h00_00_3B_6E_66_06_0F_00;   // U+0072 (r)
parameter _cS_    = 64'h00_00_3E_03_1E_30_1F_00;   // U+0073 (s)
parameter _cT_    = 64'h08_0C_3E_0C_0C_2C_18_00;   // U+0074 (t)
parameter _cU_    = 64'h00_00_33_33_33_33_6E_00;   // U+0075 (u)
parameter _cV_    = 64'h00_00_33_33_33_1E_0C_00;   // U+0076 (v)
parameter _cW_    = 64'h00_00_63_6B_7F_7F_36_00;   // U+0077 (w)
parameter _cX_    = 64'h00_00_63_36_1C_36_63_00;   // U+0078 (x)
parameter _cY_    = 64'h00_00_33_33_33_3E_30_1F;   // U+0079 (y)
parameter _cZ_    = 64'h00_00_3F_19_0C_26_3F_00;   // U+007A (z)
          
parameter _cLCUBR = 64'h38_0C_0C_07_0C_0C_38_00;   // U+007B ({)
parameter _cVBAR  = 64'h18_18_18_00_18_18_18_00;   // U+007C (|)
parameter _cRCUBR = 64'h07_0C_0C_38_0C_0C_07_00;   // U+007D (})
parameter _cTILDE = 64'h6E_3B_00_00_00_00_00_00;   // U+007E (~)

parameter _cRISCV    = 64'hF8_F3_73_38_33_87_CF_FF;
parameter _cRISCV_ = ~_cRISCV;

