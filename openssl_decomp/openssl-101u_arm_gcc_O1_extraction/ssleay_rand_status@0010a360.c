
bool ssleay_rand_status(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  CRYPTO_THREADID CStack_18;
  
  CRYPTO_THREADID_current(&CStack_18);
  if (crypto_lock_rand != 0) {
    iVar3 = 1;
    CRYPTO_lock(5,0x13,"md_rand.c",0x22f);
    iVar2 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&locking_threadid,&CStack_18);
    CRYPTO_lock(6,0x13,"md_rand.c",0x231);
    if (iVar2 == 0) goto LAB_0010a3c2;
  }
  iVar3 = 0;
  CRYPTO_lock(9,0x12,"md_rand.c",0x236);
  CRYPTO_lock(9,0x13,"md_rand.c",0x23b);
  CRYPTO_THREADID_cpy((CRYPTO_THREADID *)PTR_locking_threadid_0010a458,&CStack_18);
  CRYPTO_lock(10,0x13,"md_rand.c",0x23d);
  crypto_lock_rand = 1;
LAB_0010a3c2:
  if (initialized == 0) {
    RAND_poll();
    initialized = 1;
  }
  bVar1 = DAT_0010a450 <= entropy;
  if (iVar3 == 0) {
    crypto_lock_rand = iVar3;
    CRYPTO_lock(10,0x12,"md_rand.c",0x24c);
  }
  return bVar1;
}

