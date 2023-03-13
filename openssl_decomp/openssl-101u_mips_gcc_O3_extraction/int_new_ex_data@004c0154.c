
undefined4 int_new_ex_data(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *ptr;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  code *pcVar6;
  int iVar7;
  undefined4 *puVar8;
  
  iVar1 = def_get_class();
  if (iVar1 != 0) {
    *param_3 = 0;
    CRYPTO_lock(5,2,"ex_data.c",0x1aa);
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(iVar1 + 4));
    if (iVar2 < 1) {
      CRYPTO_lock(6,2,"ex_data.c",0x1b4);
      return 1;
    }
    ptr = (undefined4 *)CRYPTO_malloc(iVar2 << 2,"ex_data.c",0x1ad);
    if (ptr != (undefined4 *)0x0) {
      iVar4 = 0;
      puVar8 = ptr;
      do {
        iVar7 = iVar4 + 1;
        uVar3 = (*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)(iVar1 + 4),iVar4);
        *puVar8 = uVar3;
        iVar4 = iVar7;
        puVar8 = puVar8 + 1;
      } while (iVar2 != iVar7);
      iVar1 = 0;
      CRYPTO_lock(6,2,"ex_data.c",0x1b4);
      puVar8 = ptr;
      do {
        puVar5 = (undefined4 *)*puVar8;
        if ((puVar5 != (undefined4 *)0x0) && (pcVar6 = (code *)puVar5[2], pcVar6 != (code *)0x0)) {
          if (*param_3 == 0) {
            uVar3 = 0;
          }
          else {
            iVar4 = (*(code *)PTR_sk_num_006a6e2c)(*param_3);
            if (iVar1 < iVar4) {
              uVar3 = (*(code *)PTR_sk_value_006a6e24)(*param_3,iVar1);
              puVar5 = (undefined4 *)*puVar8;
              pcVar6 = (code *)puVar5[2];
            }
            else {
              puVar5 = (undefined4 *)*puVar8;
              uVar3 = 0;
              pcVar6 = (code *)puVar5[2];
            }
          }
          (*pcVar6)(param_2,uVar3,param_3,iVar1,*puVar5,puVar5[1]);
        }
        iVar1 = iVar1 + 1;
        puVar8 = puVar8 + 1;
      } while (iVar2 != iVar1);
      CRYPTO_free(ptr);
      return 1;
    }
    CRYPTO_lock(6,2,"ex_data.c",0x1b4);
    (*(code *)PTR_ERR_put_error_006a7f34)(0xf,0x6c,0x41,"ex_data.c",0x1b6);
  }
  return 0;
}

