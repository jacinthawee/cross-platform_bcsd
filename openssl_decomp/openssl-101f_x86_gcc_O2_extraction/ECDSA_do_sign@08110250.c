
ECDSA_SIG * ECDSA_do_sign(uchar *dgst,int dgst_len,EC_KEY *eckey)

{
  int iVar1;
  ECDSA_SIG *pEVar2;
  
  iVar1 = ecdsa_check(eckey);
  if (iVar1 == 0) {
    pEVar2 = (ECDSA_SIG *)0x0;
  }
  else {
    pEVar2 = (ECDSA_SIG *)(**(code **)(*(int *)(iVar1 + 0xc) + 4))(dgst,dgst_len,0,0,eckey);
  }
  return pEVar2;
}

