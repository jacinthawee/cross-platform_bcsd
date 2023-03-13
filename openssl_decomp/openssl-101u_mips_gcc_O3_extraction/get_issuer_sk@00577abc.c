
undefined4 get_issuer_sk(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = *(undefined4 *)(param_2 + 0x18);
  iVar3 = 0;
  do {
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)(uVar4);
    if (iVar2 <= iVar3) {
      *param_1 = 0;
      return 0;
    }
    iVar2 = (*(code *)PTR_sk_value_006a6e24)(uVar4,iVar3);
    iVar1 = (**(code **)(param_2 + 0x28))(param_2,param_3,iVar2);
    iVar3 = iVar3 + 1;
  } while (iVar1 == 0);
  *param_1 = iVar2;
  if (iVar2 == 0) {
    return 0;
  }
  (*(code *)PTR_CRYPTO_add_lock_006a805c)(iVar2 + 0x10,1,3,"x509_vfy.c",0x1f1);
  return 1;
}

