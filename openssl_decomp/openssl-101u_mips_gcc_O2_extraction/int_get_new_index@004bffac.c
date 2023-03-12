
int int_get_new_index(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *ptr;
  int iVar3;
  int iVar4;
  
  iVar2 = def_get_class();
  if (iVar2 == 0) {
    iVar4 = -1;
  }
  else {
    ptr = (undefined4 *)CRYPTO_malloc(0x14,"ex_data.c",0x162);
    if (ptr == (undefined4 *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xf,0x68,0x41,"ex_data.c",0x164);
      iVar4 = -1;
    }
    else {
      *ptr = param_2;
      ptr[1] = param_3;
      ptr[2] = param_4;
      ptr[4] = param_5;
      ptr[3] = param_6;
      CRYPTO_lock(9,2,"ex_data.c",0x16c);
      do {
        iVar3 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(iVar2 + 4));
        puVar1 = PTR_sk_set_006a8358;
        iVar4 = *(int *)(iVar2 + 8);
        if (iVar4 < iVar3) {
          *(int *)(iVar2 + 8) = iVar4 + 1;
          (*(code *)puVar1)(*(undefined4 *)(iVar2 + 4),iVar4,ptr);
          goto LAB_004c00a8;
        }
        iVar4 = (*(code *)PTR_sk_push_006a6fa8)(*(undefined4 *)(iVar2 + 4),0);
      } while (iVar4 != 0);
      iVar4 = -1;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xf,0x68,0x41,"ex_data.c",0x16f);
      CRYPTO_free(ptr);
LAB_004c00a8:
      CRYPTO_lock(10,2,"ex_data.c",0x177);
    }
  }
  return iVar4;
}

