
long nbiof_ctrl(BIO *param_1,int param_2,long param_3,char *param_4)

{
  long lVar1;
  bio_st *pbVar2;
  _func_603 *p_Var3;
  _func_599 *UNRECOVERED_JUMPTABLE;
  
  pbVar2 = param_1->next_bio;
  if ((pbVar2 == (bio_st *)0x0) || (param_2 == 0xc)) {
    return 0;
  }
  if (param_2 == 0x65) {
    BIO_clear_flags(param_1,0xf);
    lVar1 = BIO_ctrl(param_1->next_bio,0x65,param_3,param_4);
    BIO_copy_next_retry(param_1);
    return lVar1;
  }
  if (pbVar2 != (bio_st *)0x0) {
    if ((pbVar2->method == (BIO_METHOD *)0x0) ||
       (UNRECOVERED_JUMPTABLE = pbVar2->method->ctrl, UNRECOVERED_JUMPTABLE == (_func_599 *)0x0)) {
      ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x15d);
      lVar1 = -2;
    }
    else {
      p_Var3 = pbVar2->callback;
      if (p_Var3 == (_func_603 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0051f4c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        lVar1 = (*UNRECOVERED_JUMPTABLE)(pbVar2,param_2,param_3,param_4);
        return lVar1;
      }
      lVar1 = (*p_Var3)(pbVar2,6,param_4,param_2,param_3,1);
      if (0 < lVar1) {
        lVar1 = (*pbVar2->method->ctrl)(pbVar2,param_2,param_3,param_4);
        lVar1 = (*p_Var3)(pbVar2,0x86,param_4,param_2,param_3,lVar1);
      }
    }
    return lVar1;
  }
  return 0;
}

