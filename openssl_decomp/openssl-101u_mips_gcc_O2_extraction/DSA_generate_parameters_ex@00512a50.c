
int DSA_generate_parameters_ex
              (DSA *dsa,int bits,uchar *seed,int seed_len,int *counter_ret,ulong *h_ret,BN_GENCB *cb
              )

{
  int iVar1;
  undefined4 uVar2;
  _func_1740 *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = dsa->meth->dsa_paramgen;
  if (UNRECOVERED_JUMPTABLE != (_func_1740 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00512ac0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(dsa,bits,seed,seed_len,counter_ret,h_ret,cb);
    return iVar1;
  }
  if (bits < 0x800) {
    uVar2 = (*(code *)PTR_EVP_sha1_006a75d0)();
  }
  else {
    uVar2 = (*(code *)PTR_EVP_sha256_006a8000)();
  }
  iVar1 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar2);
  iVar1 = dsa_builtin_paramgen(dsa,bits,iVar1 << 3,uVar2,seed,seed_len,0,counter_ret,h_ret,cb);
  return iVar1;
}

