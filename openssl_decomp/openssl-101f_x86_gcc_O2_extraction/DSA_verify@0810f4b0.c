
int DSA_verify(int type,uchar *dgst,int dgst_len,uchar *sigbuf,int siglen,DSA *dsa)

{
  ASN1_VALUE *pAVar1;
  int iVar2;
  int in_GS_OFFSET;
  uchar *local_20 [3];
  DSA_SIG *local_14;
  int local_10;
  
  local_20[0] = sigbuf;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = DSA_SIG_new();
  if (local_14 == (DSA_SIG *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = -1;
    pAVar1 = ASN1_item_d2i((ASN1_VALUE **)&local_14,local_20,siglen,(ASN1_ITEM *)DSA_SIG_it);
    if (pAVar1 != (ASN1_VALUE *)0x0) {
      iVar2 = DSA_do_verify(dgst,dgst_len,local_14,dsa);
    }
    DSA_SIG_free(local_14);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

