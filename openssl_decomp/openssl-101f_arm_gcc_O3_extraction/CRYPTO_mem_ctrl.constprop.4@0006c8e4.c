
uint CRYPTO_mem_ctrl_constprop_4(void)

{
  uint uVar1;
  int iVar2;
  CRYPTO_THREADID CStack_18;
  
  uVar1 = mh_mode;
  CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
  if ((int)(mh_mode << 0x1f) < 0) {
    CRYPTO_THREADID_current(&CStack_18);
    if ((num_disable == 0) ||
       (iVar2 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_18), iVar2 != 0))
    {
      CRYPTO_lock(10,0x14,"mem_dbg.c",0xfa);
      CRYPTO_lock(9,0x1b,"mem_dbg.c",0x100);
      CRYPTO_lock(9,0x14,"mem_dbg.c",0x101);
      mh_mode = mh_mode & 0xfffffffd;
      CRYPTO_THREADID_cpy((CRYPTO_THREADID *)PTR_disabling_threadid_0006c990,&CStack_18);
    }
    num_disable = num_disable + 1;
  }
  CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
  return uVar1;
}

