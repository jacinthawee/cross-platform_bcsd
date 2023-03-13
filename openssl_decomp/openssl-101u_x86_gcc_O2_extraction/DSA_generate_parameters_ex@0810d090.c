
int DSA_generate_parameters_ex
              (DSA *dsa,int bits,uchar *seed,int seed_len,int *counter_ret,ulong *h_ret,BN_GENCB *cb
              )

{
  _func_1740 *UNRECOVERED_JUMPTABLE;
  int iVar1;
  EVP_MD *md;
  
  UNRECOVERED_JUMPTABLE = dsa->meth->dsa_paramgen;
  if (UNRECOVERED_JUMPTABLE != (_func_1740 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0810d0cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(dsa,bits,seed,seed_len,counter_ret,h_ret,cb);
    return iVar1;
  }
  if (bits < 0x800) {
    md = EVP_sha1();
  }
  else {
    md = EVP_sha256();
  }
  iVar1 = EVP_MD_size(md);
  iVar1 = dsa_builtin_paramgen(dsa,bits,iVar1 << 3,md,seed,seed_len,0,counter_ret,h_ret,cb);
  return iVar1;
}

