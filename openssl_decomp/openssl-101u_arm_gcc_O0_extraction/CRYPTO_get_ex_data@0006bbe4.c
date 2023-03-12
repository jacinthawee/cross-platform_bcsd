
void * CRYPTO_get_ex_data(CRYPTO_EX_DATA *ad,int idx)

{
  int iVar1;
  void *pvVar2;
  
  if (((_STACK *)ad->sk != (_STACK *)0x0) && (iVar1 = sk_num((_STACK *)ad->sk), idx < iVar1)) {
    pvVar2 = sk_value((_STACK *)ad->sk,idx);
    return pvVar2;
  }
  return (void *)0x0;
}

