/* Generated By:JavaCC: Do not edit this line. IDLParserTokenManager.java */
package parsing.javaccparser;
import java.io.FileNotFoundException;
import java.util.logging.Level;
import java.util.logging.Logger;
import parsing.IDLField;

/** Token Manager. */
public class IDLParserTokenManager implements IDLParserConstants
{

  /** Debug output. */
  public  java.io.PrintStream debugStream = System.out;
  /** Set debug output. */
  public  void setDebugStream(java.io.PrintStream ds) { debugStream = ds; }
private final int jjStopStringLiteralDfa_0(int pos, long active0)
{
   switch (pos)
   {
      case 0:
         if ((active0 & 0x7fc8c80L) != 0L)
         {
            jjmatchedKind = 27;
            return 13;
         }
         if ((active0 & 0x200L) != 0L)
            return 21;
         return -1;
      case 1:
         if ((active0 & 0x7fc8c80L) != 0L)
         {
            jjmatchedKind = 27;
            jjmatchedPos = 1;
            return 13;
         }
         return -1;
      case 2:
         if ((active0 & 0x7dc8c80L) != 0L)
         {
            jjmatchedKind = 27;
            jjmatchedPos = 2;
            return 13;
         }
         if ((active0 & 0x200000L) != 0L)
            return 13;
         return -1;
      case 3:
         if ((active0 & 0x65c8480L) != 0L)
         {
            jjmatchedKind = 27;
            jjmatchedPos = 3;
            return 13;
         }
         if ((active0 & 0x1800800L) != 0L)
            return 13;
         return -1;
      case 4:
         if ((active0 & 0x6148080L) != 0L)
         {
            jjmatchedKind = 27;
            jjmatchedPos = 4;
            return 13;
         }
         if ((active0 & 0x480400L) != 0L)
            return 13;
         return -1;
      case 5:
         if ((active0 & 0x2048080L) != 0L)
         {
            jjmatchedKind = 27;
            jjmatchedPos = 5;
            return 13;
         }
         if ((active0 & 0x4100000L) != 0L)
            return 13;
         return -1;
      default :
         return -1;
   }
}
private final int jjStartNfa_0(int pos, long active0)
{
   return jjMoveNfa_0(jjStopStringLiteralDfa_0(pos, active0), pos + 1);
}
private int jjStopAtPos(int pos, int kind)
{
   jjmatchedKind = kind;
   jjmatchedPos = pos;
   return pos + 1;
}
private int jjMoveStringLiteralDfa0_0()
{
   switch(curChar)
   {
      case 44:
         return jjStopAtPos(0, 14);
      case 46:
         return jjStartNfaWithStates_0(0, 9, 21);
      case 59:
         return jjStopAtPos(0, 8);
      case 91:
         return jjStopAtPos(0, 16);
      case 93:
         return jjStopAtPos(0, 17);
      case 98:
         return jjMoveStringLiteralDfa1_0(0x3000000L);
      case 99:
         return jjMoveStringLiteralDfa1_0(0x400L);
      case 100:
         return jjMoveStringLiteralDfa1_0(0x100000L);
      case 101:
         return jjMoveStringLiteralDfa1_0(0x8800L);
      case 102:
         return jjMoveStringLiteralDfa1_0(0x80000L);
      case 105:
         return jjMoveStringLiteralDfa1_0(0x200000L);
      case 108:
         return jjMoveStringLiteralDfa1_0(0x800000L);
      case 112:
         return jjMoveStringLiteralDfa1_0(0x80L);
      case 115:
         return jjMoveStringLiteralDfa1_0(0x4400000L);
      case 118:
         return jjMoveStringLiteralDfa1_0(0x40000L);
      case 123:
         return jjStopAtPos(0, 12);
      case 125:
         return jjStopAtPos(0, 13);
      default :
         return jjMoveNfa_0(0, 0);
   }
}
private int jjMoveStringLiteralDfa1_0(long active0)
{
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(0, active0);
      return 1;
   }
   switch(curChar)
   {
      case 97:
         return jjMoveStringLiteralDfa2_0(active0, 0x80L);
      case 104:
         return jjMoveStringLiteralDfa2_0(active0, 0x400000L);
      case 105:
         return jjMoveStringLiteralDfa2_0(active0, 0x40000L);
      case 108:
         return jjMoveStringLiteralDfa2_0(active0, 0x80400L);
      case 110:
         return jjMoveStringLiteralDfa2_0(active0, 0x200800L);
      case 111:
         return jjMoveStringLiteralDfa2_0(active0, 0x2900000L);
      case 116:
         return jjMoveStringLiteralDfa2_0(active0, 0x4000000L);
      case 120:
         return jjMoveStringLiteralDfa2_0(active0, 0x8000L);
      case 121:
         return jjMoveStringLiteralDfa2_0(active0, 0x1000000L);
      default :
         break;
   }
   return jjStartNfa_0(0, active0);
}
private int jjMoveStringLiteralDfa2_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(0, old0);
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(1, active0);
      return 2;
   }
   switch(curChar)
   {
      case 97:
         return jjMoveStringLiteralDfa3_0(active0, 0x400L);
      case 99:
         return jjMoveStringLiteralDfa3_0(active0, 0x80L);
      case 110:
         return jjMoveStringLiteralDfa3_0(active0, 0x800000L);
      case 111:
         return jjMoveStringLiteralDfa3_0(active0, 0x2480000L);
      case 114:
         return jjMoveStringLiteralDfa3_0(active0, 0x4040000L);
      case 116:
         if ((active0 & 0x200000L) != 0L)
            return jjStartNfaWithStates_0(2, 21, 13);
         return jjMoveStringLiteralDfa3_0(active0, 0x1008000L);
      case 117:
         return jjMoveStringLiteralDfa3_0(active0, 0x100800L);
      default :
         break;
   }
   return jjStartNfa_0(1, active0);
}
private int jjMoveStringLiteralDfa3_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(1, old0);
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(2, active0);
      return 3;
   }
   switch(curChar)
   {
      case 97:
         return jjMoveStringLiteralDfa4_0(active0, 0x80000L);
      case 98:
         return jjMoveStringLiteralDfa4_0(active0, 0x100000L);
      case 101:
         if ((active0 & 0x1000000L) != 0L)
            return jjStartNfaWithStates_0(3, 24, 13);
         return jjMoveStringLiteralDfa4_0(active0, 0x8000L);
      case 103:
         if ((active0 & 0x800000L) != 0L)
            return jjStartNfaWithStates_0(3, 23, 13);
         break;
      case 105:
         return jjMoveStringLiteralDfa4_0(active0, 0x4000000L);
      case 107:
         return jjMoveStringLiteralDfa4_0(active0, 0x80L);
      case 108:
         return jjMoveStringLiteralDfa4_0(active0, 0x2000000L);
      case 109:
         if ((active0 & 0x800L) != 0L)
            return jjStartNfaWithStates_0(3, 11, 13);
         break;
      case 114:
         return jjMoveStringLiteralDfa4_0(active0, 0x400000L);
      case 115:
         return jjMoveStringLiteralDfa4_0(active0, 0x400L);
      case 116:
         return jjMoveStringLiteralDfa4_0(active0, 0x40000L);
      default :
         break;
   }
   return jjStartNfa_0(2, active0);
}
private int jjMoveStringLiteralDfa4_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(2, old0);
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(3, active0);
      return 4;
   }
   switch(curChar)
   {
      case 97:
         return jjMoveStringLiteralDfa5_0(active0, 0x80L);
      case 101:
         return jjMoveStringLiteralDfa5_0(active0, 0x2000000L);
      case 108:
         return jjMoveStringLiteralDfa5_0(active0, 0x100000L);
      case 110:
         return jjMoveStringLiteralDfa5_0(active0, 0x4008000L);
      case 115:
         if ((active0 & 0x400L) != 0L)
            return jjStartNfaWithStates_0(4, 10, 13);
         break;
      case 116:
         if ((active0 & 0x80000L) != 0L)
            return jjStartNfaWithStates_0(4, 19, 13);
         else if ((active0 & 0x400000L) != 0L)
            return jjStartNfaWithStates_0(4, 22, 13);
         break;
      case 117:
         return jjMoveStringLiteralDfa5_0(active0, 0x40000L);
      default :
         break;
   }
   return jjStartNfa_0(3, active0);
}
private int jjMoveStringLiteralDfa5_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(3, old0);
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(4, active0);
      return 5;
   }
   switch(curChar)
   {
      case 97:
         return jjMoveStringLiteralDfa6_0(active0, 0x2040000L);
      case 100:
         return jjMoveStringLiteralDfa6_0(active0, 0x8000L);
      case 101:
         if ((active0 & 0x100000L) != 0L)
            return jjStartNfaWithStates_0(5, 20, 13);
         break;
      case 103:
         if ((active0 & 0x4000000L) != 0L)
            return jjStartNfaWithStates_0(5, 26, 13);
         return jjMoveStringLiteralDfa6_0(active0, 0x80L);
      default :
         break;
   }
   return jjStartNfa_0(4, active0);
}
private int jjMoveStringLiteralDfa6_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(4, old0);
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(5, active0);
      return 6;
   }
   switch(curChar)
   {
      case 101:
         if ((active0 & 0x80L) != 0L)
            return jjStartNfaWithStates_0(6, 7, 13);
         break;
      case 108:
         if ((active0 & 0x40000L) != 0L)
            return jjStartNfaWithStates_0(6, 18, 13);
         break;
      case 110:
         if ((active0 & 0x2000000L) != 0L)
            return jjStartNfaWithStates_0(6, 25, 13);
         break;
      case 115:
         if ((active0 & 0x8000L) != 0L)
            return jjStartNfaWithStates_0(6, 15, 13);
         break;
      default :
         break;
   }
   return jjStartNfa_0(5, active0);
}
private int jjStartNfaWithStates_0(int pos, int kind, int state)
{
   jjmatchedKind = kind;
   jjmatchedPos = pos;
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) { return pos + 1; }
   return jjMoveNfa_0(state, pos + 1);
}
static final long[] jjbitVec0 = {
   0x0L, 0x0L, 0xffffffffffffffffL, 0xffffffffffffffffL
};
private int jjMoveNfa_0(int startState, int curPos)
{
   int startsAt = 0;
   jjnewStateCnt = 77;
   int i = 1;
   jjstateSet[0] = startState;
   int kind = 0x7fffffff;
   for (;;)
   {
      if (++jjround == 0x7fffffff)
         ReInitRounds();
      if (curChar < 64)
      {
         long l = 1L << curChar;
         do
         {
            switch(jjstateSet[--i])
            {
               case 0:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddStates(0, 5);
                  else if (curChar == 47)
                     jjAddStates(6, 7);
                  else if (curChar == 34)
                     jjCheckNAddStates(8, 10);
                  else if (curChar == 39)
                     jjAddStates(11, 12);
                  else if (curChar == 46)
                     jjCheckNAdd(21);
                  else if (curChar == 35)
                     jjCheckNAddTwoStates(1, 2);
                  if ((0x3fe000000000000L & l) != 0L)
                  {
                     if (kind > 29)
                        kind = 29;
                     jjCheckNAddTwoStates(18, 19);
                  }
                  else if (curChar == 48)
                     jjAddStates(13, 14);
                  if (curChar == 48)
                  {
                     if (kind > 28)
                        kind = 28;
                     jjCheckNAddTwoStates(15, 16);
                  }
                  break;
               case 1:
                  if ((0x100000200L & l) != 0L)
                     jjCheckNAddTwoStates(1, 2);
                  break;
               case 2:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddStates(15, 18);
                  break;
               case 3:
                  if ((0x100000200L & l) != 0L)
                     jjCheckNAddTwoStates(3, 4);
                  break;
               case 4:
                  if (curChar == 34)
                     jjCheckNAdd(5);
                  break;
               case 5:
                  if ((0xfffffffbffffffffL & l) != 0L)
                     jjCheckNAddTwoStates(5, 6);
                  break;
               case 6:
                  if (curChar == 34)
                     jjCheckNAddStates(19, 21);
                  break;
               case 7:
                  if (curChar == 10 && kind > 6)
                     kind = 6;
                  break;
               case 8:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddStates(22, 25);
                  break;
               case 9:
                  if ((0x100000200L & l) != 0L)
                     jjCheckNAddStates(26, 28);
                  break;
               case 10:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddTwoStates(10, 7);
                  break;
               case 11:
                  if ((0x100000200L & l) != 0L)
                     jjCheckNAddStates(29, 33);
                  break;
               case 13:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  jjstateSet[jjnewStateCnt++] = 13;
                  break;
               case 14:
                  if (curChar != 48)
                     break;
                  if (kind > 28)
                     kind = 28;
                  jjCheckNAddTwoStates(15, 16);
                  break;
               case 15:
                  if ((0xff000000000000L & l) == 0L)
                     break;
                  if (kind > 28)
                     kind = 28;
                  jjCheckNAddTwoStates(15, 16);
                  break;
               case 17:
                  if ((0x3fe000000000000L & l) == 0L)
                     break;
                  if (kind > 29)
                     kind = 29;
                  jjCheckNAddTwoStates(18, 19);
                  break;
               case 18:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 29)
                     kind = 29;
                  jjCheckNAddTwoStates(18, 19);
                  break;
               case 20:
                  if (curChar == 46)
                     jjCheckNAdd(21);
                  break;
               case 21:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 31)
                     kind = 31;
                  jjCheckNAddStates(34, 36);
                  break;
               case 23:
                  if ((0x280000000000L & l) != 0L)
                     jjCheckNAdd(24);
                  break;
               case 24:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 31)
                     kind = 31;
                  jjCheckNAddTwoStates(24, 25);
                  break;
               case 26:
                  if (curChar == 39)
                     jjAddStates(11, 12);
                  break;
               case 27:
                  if ((0xffffff7fffffdbffL & l) != 0L)
                     jjCheckNAdd(28);
                  break;
               case 28:
                  if (curChar == 39 && kind > 33)
                     kind = 33;
                  break;
               case 30:
                  if ((0x8000008400000000L & l) != 0L)
                     jjCheckNAdd(28);
                  break;
               case 31:
                  if (curChar == 48)
                     jjCheckNAddTwoStates(32, 28);
                  break;
               case 32:
                  if ((0xff000000000000L & l) != 0L)
                     jjCheckNAddTwoStates(32, 28);
                  break;
               case 33:
                  if ((0x3fe000000000000L & l) != 0L)
                     jjCheckNAddTwoStates(34, 28);
                  break;
               case 34:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddTwoStates(34, 28);
                  break;
               case 35:
                  if (curChar == 48)
                     jjAddStates(37, 38);
                  break;
               case 37:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddTwoStates(37, 28);
                  break;
               case 39:
                  if (curChar == 34)
                     jjCheckNAddStates(8, 10);
                  break;
               case 40:
                  if ((0xfffffffbffffdbffL & l) != 0L)
                     jjCheckNAddStates(8, 10);
                  break;
               case 42:
                  if ((0x8000008400000000L & l) != 0L)
                     jjCheckNAddStates(8, 10);
                  break;
               case 43:
                  if (curChar == 34 && kind > 34)
                     kind = 34;
                  break;
               case 44:
                  if (curChar == 48)
                     jjCheckNAddStates(39, 42);
                  break;
               case 45:
                  if ((0xff000000000000L & l) != 0L)
                     jjCheckNAddStates(39, 42);
                  break;
               case 46:
                  if ((0x3fe000000000000L & l) != 0L)
                     jjCheckNAddStates(43, 46);
                  break;
               case 47:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddStates(43, 46);
                  break;
               case 48:
                  if (curChar == 48)
                     jjAddStates(47, 48);
                  break;
               case 50:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddStates(49, 52);
                  break;
               case 52:
                  if (curChar == 48)
                     jjAddStates(13, 14);
                  break;
               case 54:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 30)
                     kind = 30;
                  jjAddStates(53, 54);
                  break;
               case 57:
                  if (curChar == 47)
                     jjAddStates(6, 7);
                  break;
               case 58:
                  if (curChar == 47)
                     jjCheckNAddTwoStates(59, 60);
                  break;
               case 59:
                  if ((0xfffffffffffffbffL & l) != 0L)
                     jjCheckNAddTwoStates(59, 60);
                  break;
               case 60:
                  if (curChar == 10 && kind > 5)
                     kind = 5;
                  break;
               case 61:
                  if (curChar == 42)
                     jjCheckNAddTwoStates(62, 63);
                  break;
               case 62:
                  if ((0xfffffbffffffffffL & l) != 0L)
                     jjCheckNAddTwoStates(62, 63);
                  break;
               case 63:
                  if (curChar == 42)
                     jjAddStates(55, 56);
                  break;
               case 64:
                  if ((0xffff7fffffffffffL & l) != 0L)
                     jjCheckNAddTwoStates(65, 63);
                  break;
               case 65:
                  if ((0xfffffbffffffffffL & l) != 0L)
                     jjCheckNAddTwoStates(65, 63);
                  break;
               case 66:
                  if (curChar == 47 && kind > 35)
                     kind = 35;
                  break;
               case 67:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddStates(0, 5);
                  break;
               case 68:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddTwoStates(68, 69);
                  break;
               case 69:
                  if (curChar != 46)
                     break;
                  if (kind > 31)
                     kind = 31;
                  jjCheckNAddStates(57, 59);
                  break;
               case 70:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 31)
                     kind = 31;
                  jjCheckNAddStates(57, 59);
                  break;
               case 71:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddTwoStates(71, 20);
                  break;
               case 72:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddTwoStates(72, 73);
                  break;
               case 74:
                  if ((0x280000000000L & l) != 0L)
                     jjCheckNAdd(75);
                  break;
               case 75:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 32)
                     kind = 32;
                  jjCheckNAddTwoStates(75, 76);
                  break;
               default : break;
            }
         } while(i != startsAt);
      }
      else if (curChar < 128)
      {
         long l = 1L << (curChar & 077);
         do
         {
            switch(jjstateSet[--i])
            {
               case 0:
               case 13:
                  if ((0x7fffffe87fffffeL & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  jjCheckNAdd(13);
                  break;
               case 5:
                  jjAddStates(60, 61);
                  break;
               case 16:
                  if ((0x20100000201000L & l) != 0L && kind > 28)
                     kind = 28;
                  break;
               case 19:
                  if ((0x20100000201000L & l) != 0L && kind > 29)
                     kind = 29;
                  break;
               case 22:
                  if ((0x2000000020L & l) != 0L)
                     jjAddStates(62, 63);
                  break;
               case 25:
                  if ((0x104000001040L & l) != 0L && kind > 31)
                     kind = 31;
                  break;
               case 27:
                  if ((0xffffffffefffffffL & l) != 0L)
                     jjCheckNAdd(28);
                  break;
               case 29:
                  if (curChar == 92)
                     jjAddStates(64, 67);
                  break;
               case 30:
                  if ((0x54404610000000L & l) != 0L)
                     jjCheckNAdd(28);
                  break;
               case 36:
                  if (curChar == 120)
                     jjCheckNAdd(37);
                  break;
               case 37:
                  if ((0x7e0000007eL & l) != 0L)
                     jjCheckNAddTwoStates(37, 28);
                  break;
               case 38:
                  if (curChar == 88)
                     jjCheckNAdd(37);
                  break;
               case 40:
                  if ((0xffffffffefffffffL & l) != 0L)
                     jjCheckNAddStates(8, 10);
                  break;
               case 41:
                  if (curChar == 92)
                     jjAddStates(68, 71);
                  break;
               case 42:
                  if ((0x54404610000000L & l) != 0L)
                     jjCheckNAddStates(8, 10);
                  break;
               case 49:
                  if (curChar == 120)
                     jjCheckNAdd(50);
                  break;
               case 50:
                  if ((0x7e0000007eL & l) != 0L)
                     jjCheckNAddStates(49, 52);
                  break;
               case 51:
                  if (curChar == 88)
                     jjCheckNAdd(50);
                  break;
               case 53:
                  if (curChar == 120)
                     jjCheckNAdd(54);
                  break;
               case 54:
                  if ((0x7e0000007eL & l) == 0L)
                     break;
                  if (kind > 30)
                     kind = 30;
                  jjCheckNAddTwoStates(54, 55);
                  break;
               case 55:
                  if ((0x20100000201000L & l) != 0L && kind > 30)
                     kind = 30;
                  break;
               case 56:
                  if (curChar == 88)
                     jjCheckNAdd(54);
                  break;
               case 59:
                  jjAddStates(72, 73);
                  break;
               case 62:
                  jjCheckNAddTwoStates(62, 63);
                  break;
               case 64:
               case 65:
                  jjCheckNAddTwoStates(65, 63);
                  break;
               case 73:
                  if ((0x2000000020L & l) != 0L)
                     jjAddStates(74, 75);
                  break;
               case 76:
                  if ((0x104000001040L & l) != 0L && kind > 32)
                     kind = 32;
                  break;
               default : break;
            }
         } while(i != startsAt);
      }
      else
      {
         int i2 = (curChar & 0xff) >> 6;
         long l2 = 1L << (curChar & 077);
         do
         {
            switch(jjstateSet[--i])
            {
               case 5:
                  if ((jjbitVec0[i2] & l2) != 0L)
                     jjAddStates(60, 61);
                  break;
               case 27:
                  if ((jjbitVec0[i2] & l2) != 0L)
                     jjstateSet[jjnewStateCnt++] = 28;
                  break;
               case 40:
                  if ((jjbitVec0[i2] & l2) != 0L)
                     jjAddStates(8, 10);
                  break;
               case 59:
                  if ((jjbitVec0[i2] & l2) != 0L)
                     jjAddStates(72, 73);
                  break;
               case 62:
                  if ((jjbitVec0[i2] & l2) != 0L)
                     jjCheckNAddTwoStates(62, 63);
                  break;
               case 64:
               case 65:
                  if ((jjbitVec0[i2] & l2) != 0L)
                     jjCheckNAddTwoStates(65, 63);
                  break;
               default : break;
            }
         } while(i != startsAt);
      }
      if (kind != 0x7fffffff)
      {
         jjmatchedKind = kind;
         jjmatchedPos = curPos;
         kind = 0x7fffffff;
      }
      ++curPos;
      if ((i = jjnewStateCnt) == (startsAt = 77 - (jjnewStateCnt = startsAt)))
         return curPos;
      try { curChar = input_stream.readChar(); }
      catch(java.io.IOException e) { return curPos; }
   }
}
static final int[] jjnextStates = {
   68, 69, 71, 20, 72, 73, 58, 61, 40, 41, 43, 27, 29, 53, 56, 2, 
   3, 4, 7, 7, 8, 11, 9, 10, 7, 8, 9, 10, 7, 9, 10, 7, 
   8, 11, 21, 22, 25, 36, 38, 40, 41, 45, 43, 40, 41, 47, 43, 49, 
   51, 40, 41, 50, 43, 54, 55, 64, 66, 70, 22, 25, 5, 6, 23, 24, 
   30, 31, 33, 35, 42, 44, 46, 48, 59, 60, 74, 75, 
};

/** Token literal values. */
public static final String[] jjstrLiteralImages = {
"", null, null, null, null, null, null, "\160\141\143\153\141\147\145", "\73", 
"\56", "\143\154\141\163\163", "\145\156\165\155", "\173", "\175", "\54", 
"\145\170\164\145\156\144\163", "\133", "\135", "\166\151\162\164\165\141\154", "\146\154\157\141\164", 
"\144\157\165\142\154\145", "\151\156\164", "\163\150\157\162\164", "\154\157\156\147", 
"\142\171\164\145", "\142\157\157\154\145\141\156", "\163\164\162\151\156\147", null, null, null, 
null, null, null, null, null, null, };

/** Lexer state names. */
public static final String[] lexStateNames = {
   "DEFAULT",
};
static final long[] jjtoToken = {
   0xfffffff81L, 
};
static final long[] jjtoSkip = {
   0x7eL, 
};
protected SimpleCharStream input_stream;
private final int[] jjrounds = new int[77];
private final int[] jjstateSet = new int[154];
protected char curChar;
/** Constructor. */
public IDLParserTokenManager(SimpleCharStream stream){
   if (SimpleCharStream.staticFlag)
      throw new Error("ERROR: Cannot use a static CharStream class with a non-static lexical analyzer.");
   input_stream = stream;
}

/** Constructor. */
public IDLParserTokenManager(SimpleCharStream stream, int lexState){
   this(stream);
   SwitchTo(lexState);
}

/** Reinitialise parser. */
public void ReInit(SimpleCharStream stream)
{
   jjmatchedPos = jjnewStateCnt = 0;
   curLexState = defaultLexState;
   input_stream = stream;
   ReInitRounds();
}
private void ReInitRounds()
{
   int i;
   jjround = 0x80000001;
   for (i = 77; i-- > 0;)
      jjrounds[i] = 0x80000000;
}

/** Reinitialise parser. */
public void ReInit(SimpleCharStream stream, int lexState)
{
   ReInit(stream);
   SwitchTo(lexState);
}

/** Switch to specified lex state. */
public void SwitchTo(int lexState)
{
   if (lexState >= 1 || lexState < 0)
      throw new TokenMgrError("Error: Ignoring invalid lexical state : " + lexState + ". State unchanged.", TokenMgrError.INVALID_LEXICAL_STATE);
   else
      curLexState = lexState;
}

protected Token jjFillToken()
{
   final Token t;
   final String curTokenImage;
   final int beginLine;
   final int endLine;
   final int beginColumn;
   final int endColumn;
   String im = jjstrLiteralImages[jjmatchedKind];
   curTokenImage = (im == null) ? input_stream.GetImage() : im;
   beginLine = input_stream.getBeginLine();
   beginColumn = input_stream.getBeginColumn();
   endLine = input_stream.getEndLine();
   endColumn = input_stream.getEndColumn();
   t = Token.newToken(jjmatchedKind, curTokenImage);

   t.beginLine = beginLine;
   t.endLine = endLine;
   t.beginColumn = beginColumn;
   t.endColumn = endColumn;

   return t;
}

int curLexState = 0;
int defaultLexState = 0;
int jjnewStateCnt;
int jjround;
int jjmatchedPos;
int jjmatchedKind;

/** Get the next Token. */
public Token getNextToken() 
{
  Token matchedToken;
  int curPos = 0;

  EOFLoop :
  for (;;)
  {
   try
   {
      curChar = input_stream.BeginToken();
   }
   catch(java.io.IOException e)
   {
      jjmatchedKind = 0;
      matchedToken = jjFillToken();
      return matchedToken;
   }

   try { input_stream.backup(0);
      while (curChar <= 32 && (0x100002600L & (1L << curChar)) != 0L)
         curChar = input_stream.BeginToken();
   }
   catch (java.io.IOException e1) { continue EOFLoop; }
   jjmatchedKind = 0x7fffffff;
   jjmatchedPos = 0;
   curPos = jjMoveStringLiteralDfa0_0();
   if (jjmatchedKind != 0x7fffffff)
   {
      if (jjmatchedPos + 1 < curPos)
         input_stream.backup(curPos - jjmatchedPos - 1);
      if ((jjtoToken[jjmatchedKind >> 6] & (1L << (jjmatchedKind & 077))) != 0L)
      {
         matchedToken = jjFillToken();
         return matchedToken;
      }
      else
      {
         continue EOFLoop;
      }
   }
   int error_line = input_stream.getEndLine();
   int error_column = input_stream.getEndColumn();
   String error_after = null;
   boolean EOFSeen = false;
   try { input_stream.readChar(); input_stream.backup(1); }
   catch (java.io.IOException e1) {
      EOFSeen = true;
      error_after = curPos <= 1 ? "" : input_stream.GetImage();
      if (curChar == '\n' || curChar == '\r') {
         error_line++;
         error_column = 0;
      }
      else
         error_column++;
   }
   if (!EOFSeen) {
      input_stream.backup(1);
      error_after = curPos <= 1 ? "" : input_stream.GetImage();
   }
   throw new TokenMgrError(EOFSeen, curLexState, error_line, error_column, error_after, curChar, TokenMgrError.LEXICAL_ERROR);
  }
}

private void jjCheckNAdd(int state)
{
   if (jjrounds[state] != jjround)
   {
      jjstateSet[jjnewStateCnt++] = state;
      jjrounds[state] = jjround;
   }
}
private void jjAddStates(int start, int end)
{
   do {
      jjstateSet[jjnewStateCnt++] = jjnextStates[start];
   } while (start++ != end);
}
private void jjCheckNAddTwoStates(int state1, int state2)
{
   jjCheckNAdd(state1);
   jjCheckNAdd(state2);
}

private void jjCheckNAddStates(int start, int end)
{
   do {
      jjCheckNAdd(jjnextStates[start]);
   } while (start++ != end);
}

}
