
undefined4 SRP_generate_server_master_secret(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *ptr;
  undefined4 uVar4;
  int iVar5;
  size_t len;
  
  iVar1 = (*(code *)PTR_SRP_Verify_A_mod_N_006a8454)
                    (*(undefined4 *)(param_1 + 0x1b8),*(undefined4 *)(param_1 + 0x1a8));
  if (iVar1 == 0) {
LAB_004bb768:
    iVar1 = 0;
    iVar2 = 0;
  }
  else {
    iVar1 = (*(code *)PTR_SRP_Calc_u_006a8458)
                      (*(undefined4 *)(param_1 + 0x1b8),*(undefined4 *)(param_1 + 0x1b4),
                       *(undefined4 *)(param_1 + 0x1a8));
    if (iVar1 == 0) goto LAB_004bb768;
    iVar2 = (*(code *)PTR_SRP_Calc_server_key_006a845c)
                      (*(undefined4 *)(param_1 + 0x1b8),*(undefined4 *)(param_1 + 0x1c4),iVar1,
                       *(undefined4 *)(param_1 + 0x1c0),*(undefined4 *)(param_1 + 0x1a8));
    if (iVar2 != 0) {
      iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar2);
      iVar5 = iVar3 + 7;
      if (iVar3 + 7 < 0) {
        iVar5 = iVar3 + 0xe;
      }
      len = iVar5 >> 3;
      ptr = CRYPTO_malloc(len,"tls_srp.c",0x162);
      if (ptr != (void *)0x0) {
        (*(code *)PTR_BN_bn2bin_006a7200)(iVar2,ptr);
        uVar4 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0xc))(param_1,param_2,ptr,len);
        OPENSSL_cleanse(ptr,len);
        CRYPTO_free(ptr);
        goto LAB_004bb724;
      }
    }
  }
  uVar4 = 0xffffffff;
LAB_004bb724:
  (*(code *)PTR_BN_clear_free_006a7fa8)(iVar2);
  (*(code *)PTR_BN_clear_free_006a7fa8)(iVar1);
  return uVar4;
}
