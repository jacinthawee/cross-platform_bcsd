
int DH_up_ref(DH *dh)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a9080)(&dh->references,1,0x1a,"dh_lib.c",0xe2);
  return iVar1 < 2 ^ 1;
}

