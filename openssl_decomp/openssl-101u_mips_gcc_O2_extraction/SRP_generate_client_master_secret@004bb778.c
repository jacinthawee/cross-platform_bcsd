
undefined4 SRP_generate_client_master_secret(int param_1,undefined4 param_2)

{
  int iVar1;
  void *ptr;
  int iVar2;
  int iVar3;
  int iVar4;
  void *ptr_00;
  undefined4 uVar5;
  int iVar6;
  size_t sVar7;
  
  iVar1 = (*(code *)PTR_SRP_Verify_B_mod_N_006a8460)
                    (*(undefined4 *)(param_1 + 0x1b4),*(undefined4 *)(param_1 + 0x1a8));
  if (iVar1 == 0) {
LAB_004bb994:
    iVar1 = 0;
  }
  else {
    iVar1 = (*(code *)PTR_SRP_Calc_u_006a8458)
                      (*(undefined4 *)(param_1 + 0x1b8),*(undefined4 *)(param_1 + 0x1b4),
                       *(undefined4 *)(param_1 + 0x1a8));
    if (iVar1 == 0) goto LAB_004bb994;
    if (*(code **)(param_1 + 0x1a0) != (code *)0x0) {
      ptr = (void *)(**(code **)(param_1 + 0x1a0))(param_1,*(undefined4 *)(param_1 + 0x194));
      if (ptr != (void *)0x0) {
        iVar2 = (*(code *)PTR_SRP_Calc_x_006a8464)
                          (*(undefined4 *)(param_1 + 0x1b0),*(undefined4 *)(param_1 + 0x1a4),ptr);
        if (iVar2 == 0) {
          iVar3 = 0;
LAB_004bb9c4:
          uVar5 = 0xffffffff;
          (*(code *)PTR_BN_clear_free_006a7fa8)(iVar3);
          (*(code *)PTR_BN_clear_free_006a7fa8)(iVar2);
        }
        else {
          iVar3 = (*(code *)PTR_SRP_Calc_client_key_006a8468)
                            (*(undefined4 *)(param_1 + 0x1a8),*(undefined4 *)(param_1 + 0x1b4),
                             *(undefined4 *)(param_1 + 0x1ac),iVar2,*(undefined4 *)(param_1 + 0x1bc)
                             ,iVar1);
          if (iVar3 == 0) goto LAB_004bb9c4;
          iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar3);
          iVar6 = iVar4 + 7;
          if (iVar4 + 7 < 0) {
            iVar6 = iVar4 + 0xe;
          }
          sVar7 = iVar6 >> 3;
          ptr_00 = CRYPTO_malloc(sVar7,"tls_srp.c",0x191);
          if (ptr_00 == (void *)0x0) goto LAB_004bb9c4;
          (*(code *)PTR_BN_bn2bin_006a7200)(iVar3,ptr_00);
          uVar5 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0xc))
                            (param_1,param_2,ptr_00,sVar7);
          OPENSSL_cleanse(ptr_00,sVar7);
          CRYPTO_free(ptr_00);
          (*(code *)PTR_BN_clear_free_006a7fa8)(iVar3);
          (*(code *)PTR_BN_clear_free_006a7fa8)(iVar2);
        }
        sVar7 = (*(code *)PTR_strlen_006a9a24)(ptr);
        OPENSSL_cleanse(ptr,sVar7);
        CRYPTO_free(ptr);
        goto LAB_004bb958;
      }
    }
  }
  uVar5 = 0xffffffff;
  (*(code *)PTR_BN_clear_free_006a7fa8)(0);
  (*(code *)PTR_BN_clear_free_006a7fa8)(0);
LAB_004bb958:
  (*(code *)PTR_BN_clear_free_006a7fa8)(iVar1);
  return uVar5;
}
