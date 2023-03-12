
int DSA_verify(int type,uchar *dgst,int dgst_len,uchar *sigbuf,int siglen,DSA *dsa)

{
  ASN1_VALUE *pAVar1;
  int iVar2;
  uchar *local_1c [2];
  DSA_SIG *local_14 [2];
  
  local_1c[0] = sigbuf;
  local_14[0] = DSA_SIG_new();
  if (local_14[0] == (DSA_SIG *)0x0) {
    iVar2 = -1;
  }
  else {
    pAVar1 = ASN1_item_d2i((ASN1_VALUE **)local_14,local_1c,siglen,(ASN1_ITEM *)&DSA_SIG_it);
    if (pAVar1 == (ASN1_VALUE *)0x0) {
      iVar2 = -1;
    }
    else {
      iVar2 = DSA_do_verify(dgst,dgst_len,local_14[0],dsa);
    }
    DSA_SIG_free(local_14[0]);
  }
  return iVar2;
}

