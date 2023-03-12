
bool ssleay_rand_status(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  CRYPTO_THREADID CStack_18;
  
  CRYPTO_THREADID_current(&CStack_18);
  if (crypto_lock_rand != 0) {
    iVar3 = 1;
    CRYPTO_lock(5,0x13,"md_rand.c",0x239);
    iVar2 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&locking_threadid,&CStack_18);
    CRYPTO_lock(6,0x13,"md_rand.c",0x23b);
    if (iVar2 == 0) goto LAB_0010c10a;
  }
  iVar3 = 0;
  CRYPTO_lock(9,0x12,"md_rand.c",0x242);
  CRYPTO_lock(9,0x13,"md_rand.c",0x245);
  CRYPTO_THREADID_cpy((CRYPTO_THREADID *)PTR_locking_threadid_0010c1a0,&CStack_18);
  CRYPTO_lock(10,0x13,"md_rand.c",0x247);
  crypto_lock_rand = 1;
LAB_0010c10a:
  if (initialized == 0) {
    RAND_poll();
    initialized = 1;
  }
  bVar1 = DAT_0010c198 <= entropy;
  if (iVar3 == 0) {
    crypto_lock_rand = iVar3;
    CRYPTO_lock(10,0x12,"md_rand.c",600);
  }
  return bVar1;
}

