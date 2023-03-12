
int DSA_verify(int type,uchar *dgst,int dgst_len,uchar *sigbuf,int siglen,DSA *dsa)

{
  undefined *puVar1;
  int iVar2;
  uchar *dgst_00;
  uchar **dgst_len_00;
  DSA_SIG *sig;
  undefined1 *puVar3;
  uchar *local_24;
  DSA_SIG *local_20;
  uchar *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(uchar **)PTR___stack_chk_guard_006aabf0;
  dgst_len_00 = (uchar **)dgst;
  sig = (DSA_SIG *)dgst_len;
  local_24 = sigbuf;
  local_20 = DSA_SIG_new();
  if (local_20 == (DSA_SIG *)0x0) {
    iVar2 = -1;
  }
  else {
    dgst_len_00 = &local_24;
    puVar3 = DSA_SIG_it;
    iVar2 = (*(code *)PTR_ASN1_item_d2i_006a9798)(&local_20);
    if (iVar2 == 0) {
      iVar2 = -1;
      sig = (DSA_SIG *)siglen;
      sigbuf = puVar3;
    }
    else {
      sig = local_20;
      iVar2 = DSA_do_verify(dgst,dgst_len,local_20,dsa);
      dgst_len_00 = (uchar **)dgst_len;
      sigbuf = (uchar *)dsa;
    }
    DSA_SIG_free(local_20);
  }
  if (local_1c == *(uchar **)puVar1) {
    return iVar2;
  }
  dgst_00 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x00515b08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(*(DSA_METHOD **)((int)sigbuf + 0x3c))->dsa_do_verify)
                    (dgst_00,(int)dgst_len_00,sig,(DSA *)sigbuf);
  return iVar2;
}

