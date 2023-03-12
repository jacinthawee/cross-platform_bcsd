
void CRYPTO_mem_leaks_fp(FILE *param_1)

{
  undefined4 uVar1;
  bio_st *bio;
  int iVar2;
  
  if (mh != 0) {
    CRYPTO_mem_ctrl_constprop_5();
    uVar1 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    bio = (bio_st *)(*(code *)PTR_BIO_new_006a7fa4)(uVar1);
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
    if ((((mh_mode & 1) == 0) || (iVar2 = num_disable + -1, num_disable == 0)) ||
       (num_disable = iVar2, iVar2 != 0)) {
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
    }
    else {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
    }
    if (bio != (bio_st *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(bio,0x6a,0,param_1);
      CRYPTO_mem_leaks(bio);
                    /* WARNING: Could not recover jumptable at 0x004c2cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_BIO_free_006a7f70)(bio);
      return;
    }
  }
  return;
}

