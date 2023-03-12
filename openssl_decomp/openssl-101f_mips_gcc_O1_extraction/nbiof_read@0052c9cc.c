
int nbiof_read(BIO *param_1,undefined *param_2,uint param_3,char *param_4)

{
  undefined *puVar1;
  int iVar2;
  long lVar3;
  BIO *b;
  bio_st *pbVar4;
  _func_603 *p_Var5;
  _func_599 *UNRECOVERED_JUMPTABLE;
  byte local_1d;
  BIO *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(BIO **)PTR___stack_chk_guard_006aabf0;
  iVar2 = 0;
  if (param_2 != (undefined *)0x0) {
    if (param_1->next_bio == (bio_st *)0x0) {
      iVar2 = 0;
    }
    else {
      BIO_clear_flags(param_1,0xf);
      RAND_pseudo_bytes(&local_1d,1);
      if ((int)(local_1d & 7) <= (int)param_3) {
        param_3 = local_1d & 7;
      }
      if ((local_1d & 7) == 0) {
        param_2 = &DAT_00000009;
        BIO_set_flags(param_1,9);
        iVar2 = -1;
      }
      else {
        iVar2 = BIO_read(param_1->next_bio,param_2,param_3);
        if (iVar2 < 0) {
          BIO_copy_next_retry(param_1);
        }
      }
    }
  }
  if (local_1c == *(BIO **)puVar1) {
    return iVar2;
  }
  b = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pbVar4 = b->next_bio;
  if ((pbVar4 == (bio_st *)0x0) || (param_2 == &SUB_0000000c)) {
    return 0;
  }
  if (param_2 == &DAT_00000065) {
    BIO_clear_flags(b,0xf);
    lVar3 = BIO_ctrl(b->next_bio,0x65,param_3,param_4);
    BIO_copy_next_retry(b);
    return lVar3;
  }
  if (pbVar4 != (bio_st *)0x0) {
    if ((pbVar4->method == (BIO_METHOD *)0x0) ||
       (UNRECOVERED_JUMPTABLE = pbVar4->method->ctrl, UNRECOVERED_JUMPTABLE == (_func_599 *)0x0)) {
      ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x168);
      iVar2 = -2;
    }
    else {
      p_Var5 = pbVar4->callback;
      if (p_Var5 == (_func_603 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005213d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar2 = (*UNRECOVERED_JUMPTABLE)(pbVar4,(int)param_2,param_3,param_4);
        return iVar2;
      }
      iVar2 = (*p_Var5)(pbVar4,6,param_4,(int)param_2,param_3,1);
      if (0 < iVar2) {
        lVar3 = (*pbVar4->method->ctrl)(pbVar4,(int)param_2,param_3,param_4);
        iVar2 = (*p_Var5)(pbVar4,0x86,param_4,(int)param_2,param_3,lVar3);
      }
    }
    return iVar2;
  }
  return 0;
}

