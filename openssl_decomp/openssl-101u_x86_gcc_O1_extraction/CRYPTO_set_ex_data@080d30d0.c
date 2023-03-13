
int CRYPTO_set_ex_data(CRYPTO_EX_DATA *ad,int idx,void *val)

{
  int iVar1;
  int iVar2;
  _STACK *p_Var3;
  
  p_Var3 = (_STACK *)ad->sk;
  if (p_Var3 == (_STACK *)0x0) {
    p_Var3 = sk_new_null();
    ad->sk = (stack_st_void *)p_Var3;
    if (p_Var3 == (_STACK *)0x0) {
      ERR_put_error(0xf,0x66,0x41,"ex_data.c",0x267);
      return 0;
    }
  }
  iVar1 = sk_num(p_Var3);
  while( true ) {
    if (idx < iVar1) {
      sk_set((_STACK *)ad->sk,idx,val);
      return 1;
    }
    iVar2 = sk_push((_STACK *)ad->sk,(void *)0x0);
    if (iVar2 == 0) break;
    iVar1 = iVar1 + 1;
  }
  ERR_put_error(0xf,0x66,0x41,"ex_data.c",0x26f);
  return 0;
}

