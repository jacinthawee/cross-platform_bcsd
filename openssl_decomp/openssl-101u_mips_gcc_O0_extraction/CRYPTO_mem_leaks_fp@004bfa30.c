
void CRYPTO_mem_leaks_fp(FILE *param_1)

{
  undefined4 uVar1;
  bio_st *bio;
  int iVar2;
  
  if (mh != 0) {
    CRYPTO_mem_ctrl_constprop_5();
    uVar1 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    bio = (bio_st *)(*(code *)PTR_BIO_new_006a6ea4)(uVar1);
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
    if ((((mh_mode & 1) == 0) || (iVar2 = num_disable + -1, num_disable == 0)) ||
       (num_disable = iVar2, iVar2 != 0)) {
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
    }
    else {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
    }
    if (bio != (bio_st *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(bio,0x6a,0,param_1);
      CRYPTO_mem_leaks(bio);
                    /* WARNING: Could not recover jumptable at 0x004bfb34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_BIO_free_006a6e70)(bio);
      return;
    }
  }
  return;
}

