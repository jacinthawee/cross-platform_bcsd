
int ECDSA_do_verify(uchar *dgst,int dgst_len,ECDSA_SIG *sig,EC_KEY *eckey)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ecdsa_check_006a9890)(eckey);
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x005170e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)(iVar1 + 0xc) + 0xc))(dgst,dgst_len,sig,eckey);
    return iVar1;
  }
  return 0;
}

