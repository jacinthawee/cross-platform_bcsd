
int CRYPTO_set_ex_data(CRYPTO_EX_DATA *ad,int idx,void *val)

{
  _STACK *p_Var1;
  int iVar2;
  
  p_Var1 = (_STACK *)ad->sk;
  if (p_Var1 == (_STACK *)0x0) {
    p_Var1 = sk_new_null();
    iVar2 = 0x25d;
    ad->sk = (stack_st_void *)p_Var1;
    if (p_Var1 == (_STACK *)0x0) goto LAB_0006e038;
  }
  iVar2 = sk_num(p_Var1);
  do {
    if (idx < iVar2) {
      sk_set((_STACK *)ad->sk,idx,val);
      return 1;
    }
    p_Var1 = (_STACK *)sk_push((_STACK *)ad->sk,(void *)0x0);
    iVar2 = iVar2 + 1;
  } while (p_Var1 != (_STACK *)0x0);
  iVar2 = 0x267;
LAB_0006e038:
  ERR_put_error(0xf,0x66,0x41,"ex_data.c",iVar2);
  return (int)p_Var1;
}

