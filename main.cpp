#include <iostream>
#include <vector>

using namespace std;

const string bin4bit[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
const string bin3bit[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
const string bin2bit[4] = {"00", "01", "01", "11"};
string Atoms = "pqrs";
string newstr;
int p, q, r, s;
vector<string> v;
vector<string> ans;

void buildNewString(string formula)
{
   newstr = formula;
   for (int i = 0; i < formula.length(); i++)
   {
      switch (formula[i])
      {
      case 'p':
         newstr[i] = p + '0';
         break;
      case 'q':
         newstr[i] = q + '0';
         break;
      case 'r':
         newstr[i] = r + '0';
         break;
      case 's':
         newstr[i] = s + '0';
         break;
      default:
         break;
      }
   }
}

int solve(int l, int r)
{
   if (r - l == 1)
   {
      return newstr[l] - '0';
   }
   l++, r--;
   if (r - l == 2)
   {
      return 1 - (newstr[l + 1] - '0');
   }
   if (r - l == 3)
   {
      if (newstr[l + 1] == '|')
         return (newstr[l] - '0') | (newstr[l + 2] - '0');
      else if (newstr[l + 1] == '&')
         return (newstr[l] - '0') & (newstr[l + 2] - '0');
      else if (newstr[l + 1] == '>')
         return !(newstr[l] - '0') | (newstr[l + 2] - '0');
   }
   if (newstr[l] == '~')
      return 1 - solve(l + 1, r);
   int open = 0, close = 0;
   for (int i = l; i <= r; i++)
   {
      if (newstr[i] == '(')
         open++;
      else if (newstr[i] == ')')
         close++;
      else if (newstr[i] == '&' && open == close)
      {
         return solve(l, i) && solve(i + 1, r);
      }
      else if (newstr[i] == '|' && open == close)
      {
         return solve(l, i) || solve(i + 1, r);
      }
      else if (newstr[i] == '>' && open == close)
      {
         return !(solve(l, i)) || solve(i + 1, r);
      }
   }
   return 0;
}

string reverse(string str)
{
   string ans = "";
   for (int i = str.length() - 1; i >= 0; i--)
      ans += str[i];
   return ans;
}

string truthTable(string formula, string C_Atoms)
{
   string result = "";
   if (C_Atoms == "0000" || C_Atoms == "1111" || C_Atoms == "1000" || C_Atoms == "1100" || C_Atoms == "1110")
   {
      for (p = 1; p >= 0; p--)
         for (q = 1; q >= 0; q--)
            for (r = 1; r >= 0; r--)
               for (s = 1; s >= 0; s--)
               {
                  buildNewString(formula);
                  result += ((solve(0, formula.length()) == 1) ? 'T' : 'F');
               }
   }
   else if (C_Atoms == "1101")
   {
      for (p = 1; p >= 0; p--)
         for (q = 1; q >= 0; q--)
            for (s = 1; s >= 0; s--)
               for (r = 1; r >= 0; r--)
               {
                  buildNewString(formula);
                  result += ((solve(0, formula.length()) == 1) ? 'T' : 'F');
               }
   }
   else if (C_Atoms == "1011")
   {
      for (p = 1; p >= 0; p--)
         for (r = 1; r >= 0; r--)
            for (s = 1; s >= 0; s--)
               for (q = 1; q >= 0; q--)
               {
                  buildNewString(formula);
                  result += ((solve(0, formula.length()) == 1) ? 'T' : 'F');
               }
   }
   else if (C_Atoms == "0111" || C_Atoms == "0110" || C_Atoms == "0100")
   {
      for (q = 1; q >= 0; q--)
         for (r = 1; r >= 0; r--)
            for (s = 1; s >= 0; s--)
               for (p = 1; p >= 0; p--)
               {
                  buildNewString(formula);
                  result += ((solve(0, formula.length()) == 1) ? 'T' : 'F');
               }
   }
   else if (C_Atoms == "0011" || C_Atoms == "0010")
   {
      for (r = 1; r >= 0; r--)
         for (s = 1; s >= 0; s--)
            for (p = 1; p >= 0; p--)
               for (q = 1; q >= 0; q--)
               {
                  buildNewString(formula);
                  result += ((solve(0, formula.length()) == 1) ? 'T' : 'F');
               }
   }
   else if (C_Atoms == "0001")
   {
      for (s = 1; s >= 0; s--)
         for (p = 1; p >= 0; p--)
            for (q = 1; q >= 0; q--)
               for (r = 1; r >= 0; r--)
               {
                  buildNewString(formula);
                  result += ((solve(0, formula.length()) == 1) ? 'T' : 'F');
               }
   }
   else if (C_Atoms == "1010")
   {
      for (p = 1; p >= 0; p--)
         for (r = 1; r >= 0; r--)
            for (q = 1; q >= 0; q--)
               for (s = 1; s >= 0; s--)
               {
                  buildNewString(formula);
                  result += ((solve(0, formula.length()) == 1) ? 'T' : 'F');
               }
   }
   else if (C_Atoms == "1001")
   {
      for (p = 1; p >= 0; p--)
         for (s = 1; s >= 0; s--)
            for (q = 1; q >= 0; q--)
               for (r = 1; r >= 0; r--)
               {
                  buildNewString(formula);
                  result += ((solve(0, formula.length()) == 1) ? 'T' : 'F');
               }
   }
   else if (C_Atoms == "0101")
   {
      for (q = 1; q >= 0; q--)
         for (s = 1; s >= 0; s--)
            for (p = 1; p >= 0; p--)
               for (r = 1; r >= 0; r--)
               {
                  buildNewString(formula);
                  result += ((solve(0, formula.length()) == 1) ? 'T' : 'F');
               }
   }
   return reverse(result);
}

void parse_A_and_B_Formula(string inputFormula, string &AFormula, string &BFormula)
{
   int open = 0, close = 0;
   for (int i = 1; i < inputFormula.length(); i++)
   {
      if (inputFormula[i] == '(')
         open++;
      if (inputFormula[i] == ')')
         close++;
      if (open == close && inputFormula[i + 1] == '>')
      {
         AFormula = inputFormula.substr(1, i);
         BFormula = inputFormula.substr(i + 2, inputFormula.length() - i - 3);
         break;
      }
   }
}

string CalculateTruthOfCFormula(string TruthTableOfAFormula, string TruthTableOfBFormula, string TruthTableOfCFormula)
{
   for (int i = 0; i < TruthTableOfAFormula.length(); i++)
   {
      if (TruthTableOfAFormula[i] == 'T')
      {
         TruthTableOfCFormula[i] = 'T';
      }
      if (TruthTableOfBFormula[i] == 'F')
      {
         TruthTableOfCFormula[i] = 'F';
      }
   }
   return TruthTableOfCFormula;
}

string FindAtoms(string Formula)
{
   string Atoms = "0000";
   for (int i = 0; i < Formula.length(); i++)
   {
      switch (Formula[i])
      {
      case 'p':
         Atoms[0] = '1';
         break;
      case 'q':
         Atoms[1] = '1';
         break;
      case 'r':
         Atoms[2] = '1';
         break;
      case 's':
         Atoms[3] = '1';
         break;
      default:
         break;
      }
   }
   return Atoms;
}

string FindSubscriptionAtoms(string AFormula, string BFormula)
{
   string AvailableAtoms = "pqrs", A_Atoms = "0000", B_Atoms = "0000", C_Atoms = "0000";
   A_Atoms = FindAtoms(AFormula);
   B_Atoms = FindAtoms(BFormula);
   for (int i = 0; i < A_Atoms.length(); i++)
      C_Atoms[i] = ((A_Atoms[i] - '0') && (B_Atoms[i] - '0')) ? '1' : '0';

   return C_Atoms;
}

void GenerateAllValidC(string truthTable, string truth, int i)
{
   if (i == truthTable.length())
   {
      v.push_back(truth);
      return;
   }
   if (truthTable[i] == 'X')
   {
      truth[i] = 'T';

      GenerateAllValidC(truthTable, truth, i + 1);

      truth[i] = 'F';
      GenerateAllValidC(truthTable, truth, i + 1);
   }
   else
   {
      truth[i] = truthTable[i];
      GenerateAllValidC(truthTable, truth, i + 1);
   }
}

int FindNumOfSubscriptionAtoms(string C_Atoms)
{
   int counter = 0;
   for (int i = 0; i < C_Atoms.length(); i++)
      if (C_Atoms[i] - '0')
         counter++;
   return counter;
}

void CheckVladityOfCWithOneAtom(string C_Atoms)
{
   vector<string> ValidC;
   for (int i = 0; i < v.size(); i++)
   {
      if ((v[i].substr(0, 8) == "TTTTTTTT" || v[i].substr(0, 8) == "FFFFFFFF") && (v[i].substr(8) == "TTTTTTTT" || v[i].substr(8) == "FFFFFFFF"))
      {
         string str;
         ValidC.push_back(str + v[i][0] + v[i][15]);
      }
   }
   int first = 0;
   for (int i=0;i<C_Atoms.length();i++){
      if(C_Atoms[i] == 1)
         first = 1;
   }
   for(int i=0;i<ValidC.size();i++){
      string tmp = ValidC[i];
      if( tmp == "FF"){
         cout << "(" << Atoms[first] << "&(~" << Atoms[first] << "))" << endl;
      }else if(tmp == "TT"){
         cout << "(" << Atoms[first] << "|(~" << Atoms[first] << "))" << endl;
      }else if(tmp == "TF"){
         cout << "(~" << Atoms[first] << ")" << endl;
      }else if(tmp == "FT"){
         cout << Atoms[first] << endl;
      }
   }

}

string makeTwoAtomicMinterms(string truthOfC, int first, int second, int k)
{
   string tmp = "(";
   if (bin2bit[k][0] == '1')
      tmp.push_back(Atoms[first]);
   else
   {
      tmp.append("(~" );
      tmp.push_back(Atoms[first]);
      tmp.push_back(')');
   }
   tmp.push_back('&');
   if (bin2bit[k][1] == '1')
      tmp.push_back(Atoms[second]);
   else
   {
      tmp.append("(~");
      tmp.push_back(Atoms[second]);
      tmp.push_back(')');
   }
   tmp.push_back(')');
   return tmp;
}

void makeFinalWFFCWithTwoAtoms(string C_Atoms, vector<string> ValidC)
{
   int first, last = 0;
   for (int i = 0; i < C_Atoms.length(); i++)
   {
      if (C_Atoms[i] == '1')
      {
         first = i;
         break;
      }
   }
   for (int i = C_Atoms.length() - 1; i >= 0; i--)
   {
      if (C_Atoms[i] == '1')
      {
         last = i;
         break;
      }
   }
   for (int i = 0; i < ValidC.size(); i++)
   {
      string truthOfC = ValidC[i];
      if (truthOfC == "FFFF")
      {
         cout << "(" << Atoms[first] << "&(~" << Atoms[first] << "))"<< endl;
      }
      else
      {
         vector<int> PosOfT;
         for (int k = 0; k < truthOfC.length(); k++)
         {
            if(truthOfC[k] == 'T')
               PosOfT.push_back(k);
         }
         string firstMinterm , secondMinterm,thirdMinterm,foutthMinterm;
         switch (PosOfT.size())
         {
         case 1:
            firstMinterm = makeTwoAtomicMinterms(truthOfC, first, last, PosOfT[0]);
            cout << firstMinterm << endl;
            break;
         case 2:
            firstMinterm = makeTwoAtomicMinterms(truthOfC, first, last, PosOfT[0]);
            secondMinterm = makeTwoAtomicMinterms(truthOfC, first, last, PosOfT[1]);
            cout << "(" << firstMinterm << "|" << secondMinterm << ")" << endl;
            break;
         case 3:
            firstMinterm = makeTwoAtomicMinterms(truthOfC, first, last, PosOfT[0]);
            secondMinterm = makeTwoAtomicMinterms(truthOfC, first, last, PosOfT[1]);
            thirdMinterm = makeTwoAtomicMinterms(truthOfC, first, last, PosOfT[2]);
            cout << "("
                 << "(" << firstMinterm << "|" << secondMinterm << ")"
                 << "|" << thirdMinterm << ")" << endl;
            break;
         case 4:
            firstMinterm = makeTwoAtomicMinterms(truthOfC, first, last, PosOfT[0]);
            secondMinterm = makeTwoAtomicMinterms(truthOfC, first, last, PosOfT[1]);
            thirdMinterm = makeTwoAtomicMinterms(truthOfC, first, last, PosOfT[2]);
            foutthMinterm = makeTwoAtomicMinterms(truthOfC, first, last, PosOfT[3]);
            cout
                << "("
                << "(" << firstMinterm << "|" << secondMinterm << ")"
                << "|"
                << "(" << thirdMinterm << "|" << foutthMinterm << ")"
                << ")" << endl;
            break;
         default:
            break;
         }
      }
   }
}

void CheckVladityOfCWithTwoAtoms(string C_Atoms)
{
   vector<string> ValidC;
   for (int i = 0; i < v.size(); i++)
   {
      if ((v[i].substr(0, 4) == "TTTT" || v[i].substr(0, 4) == "FFFF") && (v[i].substr(4, 4) == "TTTT" || v[i].substr(4, 4) == "FFFF") && (v[i].substr(8, 4) == "TTTT" || v[i].substr(8, 4) == "FFFF") && (v[i].substr(12, 4) == "TTTT" || v[i].substr(12, 4) == "FFFF"))
      {
         string str;
         ValidC.push_back(str + v[i][0] + v[i][4] + v[i][8] + v[i][12]);
      }
   }
   makeFinalWFFCWithTwoAtoms(C_Atoms, ValidC);
}

string makeThreeAtomicMinterms(int row , int first , int second , int third){
   // cout << first << " " << second << "  "<< third << "   "<< row << endl;
   string truth = bin3bit[row];
   int arr[3] = {first,second,third};
   string ans = "((";
   for(int i=0;i<3;i++){
      if(truth[i] == '0'){
         ans.append("(~");
         ans.push_back(Atoms[arr[i]]);
         ans.push_back(')');
      }else{
         ans.push_back(Atoms[arr[i]]);
      }
      if(i == 0)
         ans.push_back('&');
      if(i==1)
         ans.append(")&");   
   }
   ans.push_back(')');
   // cout << " minterm that we made is : " << ans << endl;
   return ans;
}

void BuildFinalCWithThreeAtoms(string truthTableOfC , int first , int second , int third ){
   int numOfMinTerm = 0;
   int counter = 0;
   string res = "(";
   for(int i=0;i<truthTableOfC.length();i++){
      if(truthTableOfC[i] == 'T'){
         if(counter >= 2){
            res = "(" + res + "|";
         }else if(counter == 1) {
            res.push_back('|');
         }
         string min = makeThreeAtomicMinterms(i , first ,  second , third);
         res.append(min);
         if(counter != 0){
            res.push_back(')');
         }
         numOfMinTerm++;
         counter ++;
      }
   }
   int open = 0;
   int close = 0;
   for (int i=0;i<res.length();i++){
      if(res[i] == '('){
         open++;
      }else if(res[i]==')'){
         close++;
      }
   }
   for(int i=0;i<open-close;i++){
      res.push_back(')');
   }
   res.push_back(')');
   if(numOfMinTerm == 1){
      res = res.substr(1);
      res.pop_back();
   }
   cout << res << endl;
}

void makeFinalWFFCWithThreeAtoms(string C_Atoms, vector<string> vallidC){
   int first=-1 , second=-1 , third =-1;
   for (int i=0 ; i< C_Atoms.length();i++){
      if (C_Atoms[i] - '0')
      {
         if (first==-1)
            first = i;
         else if (second == -1)
            second = i ;
         else if (third == -1)
            third = i;   
      }
   }

   for(int i=0;i<vallidC.size();i++){
      string truthTableOfC = vallidC[i];
      if (truthTableOfC == "FFFFFFFFF"){
         cout << "(" << Atoms[first] << "&(~" << Atoms[first] << "))" << endl;
      }else {
         BuildFinalCWithThreeAtoms(truthTableOfC , first,second,third);
      }
   }

}

void CheckVladityOfCWithThreeAtoms(string C_Atoms)
{
   vector<string> ValidC;
   for (int i = 0; i < v.size(); i++)
   {
      if ((v[i].substr(0, 2) == "TT" || v[i].substr(0, 2) == "FF") && (v[i].substr(2, 2) == "TT" || v[i].substr(2, 2) == "FF") && (v[i].substr(4, 2) == "TT" || v[i].substr(4, 2) == "FF") && (v[i].substr(6, 2) == "TT" || v[i].substr(6, 2) == "FF") && (v[i].substr(8, 2) == "TT" || v[i].substr(8, 2) == "FF") && (v[i].substr(10, 2) == "TT" || v[i].substr(10, 2) == "FF") && (v[i].substr(12, 2) == "TT" || v[i].substr(12, 2) == "FF") && (v[i].substr(14, 2) == "TT" || v[i].substr(14, 2) == "FF"))
      {
         string str;
         ValidC.push_back(str + v[i][0] + v[i][2] + v[i][4] + v[i][6] + v[i][8] + v[i][10] + v[i][12] + v[i][14]);
      }
   }
   makeFinalWFFCWithThreeAtoms(C_Atoms,ValidC);
}

string makeFourAtomicMinterms(int row){
   string truth = bin4bit[row];
   string ans = "((";
   for(int i=0;i<4;i++){
      if(truth[i] == '0'){
         ans.append("(~");
         ans.push_back(Atoms[i]);
         ans.push_back(')');
      }else{
         ans.push_back(Atoms[i]);
      }
      if(i == 0 || i == 2)
         ans.push_back('&');
      if(i==1)
         ans.append(")&(");   
   }
   ans.append("))");
   return ans;
}

void BuildFinalCWithFourAtoms(string truthTableOfC){
   int numOfMinTerm = 0;
   int counter = 0;
   string res = "(";
   for(int i=0;i<truthTableOfC.length();i++){
      if(truthTableOfC[i] == 'T'){
         if(counter >= 2){
            res = "(" + res + "|";
         }else if(counter == 1) {
            res.push_back('|');
         }
         string min = makeFourAtomicMinterms(i);
         res.append(min);
         if(counter != 0){
            res.push_back(')');
         }
         numOfMinTerm++;
         counter ++;
      }
   }
   int open = 0;
   int close = 0;
   for (int i=0;i<res.length();i++){
      if(res[i] == '('){
         open++;
      }else if(res[i]==')'){
         close++;
      }
   }
   for(int i=0;i<open-close;i++){
      res.push_back(')');
   }
   
   if(numOfMinTerm == 1){
      res = res.substr(1);
      res.pop_back();
   }
   cout << res << endl;
}

void makeFinalWFFCWithFourAtoms(vector<string> ValidC){
   for (int i=0;i<ValidC.size();i++){
      string truthTableOfC = ValidC[i];
      if (truthTableOfC == "FFFFFFFFFFFFFFFF"){
         cout << "(" << Atoms[0] << "&(~" << Atoms[0] << "))" << endl;
      }else{
         BuildFinalCWithFourAtoms(truthTableOfC);
      }
   }

}

void CheckVladityOfCWithFourAtoms(string C_Atoms)
{
   vector<string> ValidC = v;
   // cout << ValidC.size() ;
   // return;
   makeFinalWFFCWithFourAtoms(ValidC);
}

void FindFinalC(string C_Atoms)
{
   switch (FindNumOfSubscriptionAtoms(C_Atoms))
   {
   case 1:
      CheckVladityOfCWithOneAtom(C_Atoms);
      break;
   case 2:
      CheckVladityOfCWithTwoAtoms(C_Atoms);
      break;
   case 3:
      CheckVladityOfCWithThreeAtoms(C_Atoms);
      break;
   case 4:
      CheckVladityOfCWithFourAtoms(C_Atoms);
      break;
   default:
      break;
   }
}

int main()
{
   string inputFormula, AFormula, BFormula;
   cin >> inputFormula;
   parse_A_and_B_Formula(inputFormula, AFormula, BFormula);

   // cout << "A Formula : " << AFormula << "     B Formula : " << BFormula << endl;

   string C_Atoms = FindSubscriptionAtoms(AFormula, BFormula);
   // cout << " available atoms for C : " << C_Atoms << endl;

   string TruthTableOfAFormula = truthTable(AFormula, C_Atoms);
   string TruthTableOfBFormula = truthTable(BFormula, C_Atoms);
   string TruthTableOfCFormula = "XXXXXXXXXXXXXXXX";

   // cout << "Truth Table of A Formula : " << TruthTableOfAFormula << "    Truth Table of B Formula : " << TruthTableOfBFormula << endl;

   TruthTableOfCFormula = CalculateTruthOfCFormula(TruthTableOfAFormula, TruthTableOfBFormula, TruthTableOfCFormula);
   // cout << "Truth Table of C is : " << TruthTableOfCFormula << endl << endl;

   GenerateAllValidC(TruthTableOfCFormula, "XXXXXXXXXXXXXXXX", 0);
   FindFinalC(C_Atoms);
   return 0;
}