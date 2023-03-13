
bool rinf_cb(int param_1,int *param_2)

{
  int iVar1;
  _STACK *p_Var2;
  
  if (param_1 != 1) {
    return true;
  }
  iVar1 = *param_2;
  p_Var2 = sk_new_null();
  *(_STACK **)(iVar1 + 0x18) = p_Var2;
  return p_Var2 != (_STACK *)0x0;
}

