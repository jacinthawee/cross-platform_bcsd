
CRYPTO_dynlock_value * CRYPTO_get_dynlock_value(int i)

{
  bool bVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  uVar5 = ~i;
  if (i == 0) {
    uVar5 = 0;
  }
  if (locking_callback != (code *)0x0) {
    (*locking_callback)(9,0x1d,s_cryptlib_c_0064cbb4,0x156);
  }
  if (((dyn_locks != 0) && (iVar3 = (*(code *)PTR_sk_num_006a6e2c)(), (int)uVar5 < iVar3)) &&
     (piVar4 = (int *)(*(code *)PTR_sk_value_006a6e24)(dyn_locks,uVar5), pcVar2 = locking_callback,
     piVar4 != (int *)0x0)) {
    bVar1 = locking_callback != (code *)0x0;
    *piVar4 = *piVar4 + 1;
    if (bVar1) {
      (*pcVar2)(10,0x1d,s_cryptlib_c_0064cbb4,0x15d);
    }
    return (CRYPTO_dynlock_value *)piVar4[1];
  }
  if (locking_callback != (code *)0x0) {
    (*locking_callback)(10,0x1d,s_cryptlib_c_0064cbb4,0x15d);
  }
  return (CRYPTO_dynlock_value *)0x0;
}

