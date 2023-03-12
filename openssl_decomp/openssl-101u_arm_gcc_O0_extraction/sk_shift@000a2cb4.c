
void * sk_shift(_STACK *st)

{
  _STACK **pp_Var1;
  int in_r1;
  _STACK **pp_Var2;
  int in_r3;
  int iVar3;
  _STACK *p_Var4;
  
  p_Var4 = st;
  if (st != (_STACK *)0x0) {
    if (st->num < 1) {
      p_Var4 = (_STACK *)0x0;
    }
    else {
      pp_Var2 = (_STACK **)st->data;
      iVar3 = st->num + -1;
      if (iVar3 != 0) {
        in_r1 = 4;
        in_r3 = 0;
      }
      p_Var4 = *pp_Var2;
      if (iVar3 != 0) {
        while( true ) {
          pp_Var1 = (_STACK **)((int)pp_Var2 + in_r1);
          in_r1 = in_r1 + 4;
          pp_Var2[in_r3] = *pp_Var1;
          in_r3 = in_r3 + 1;
          if (iVar3 <= in_r3) break;
          pp_Var2 = (_STACK **)st->data;
        }
      }
      st->num = iVar3;
    }
  }
  return p_Var4;
}

