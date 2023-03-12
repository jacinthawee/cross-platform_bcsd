
undefined4 add_cert_dir_isra_0(int *param_1,char *param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 uVar10;
  
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,100,0x71,"by_dir.c",0xd7);
    return 0;
  }
  pcVar8 = param_2 + 1;
  do {
    if (((pcVar8[-1] == ':') || (pcVar9 = param_2, pcVar8[-1] == '\0')) &&
       (pcVar7 = pcVar8 + (-1 - (int)param_2), pcVar9 = pcVar8, pcVar7 != (char *)0x0)) {
      iVar6 = 0;
      iVar2 = (*(code *)PTR_sk_num_006a7f2c)(*param_1);
      if (0 < iVar2) {
        do {
          puVar3 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(*param_1,iVar6);
          uVar10 = *puVar3;
          pcVar4 = (char *)(*(code *)PTR_strlen_006aab30)(uVar10);
          if ((pcVar4 == pcVar7) &&
             (iVar2 = (*(code *)PTR_strncmp_006aaa7c)(uVar10,param_2,pcVar7), iVar2 == 0)) break;
          iVar6 = iVar6 + 1;
          iVar2 = (*(code *)PTR_sk_num_006a7f2c)(*param_1);
        } while (iVar6 < iVar2);
      }
      iVar2 = (*(code *)PTR_sk_num_006a7f2c)(*param_1);
      if (iVar2 <= iVar6) {
        if (*param_1 == 0) {
          iVar2 = (*(code *)PTR_sk_new_null_006a80a4)();
          *param_1 = iVar2;
          if (iVar2 == 0) {
            (*(code *)PTR_ERR_put_error_006a9030)(0xb,100,0x41,"by_dir.c",0xf4);
            return 0;
          }
        }
        piVar5 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0xc,"by_dir.c",0xf8);
        puVar1 = PTR_sk_new_006a91b4;
        if (piVar5 == (int *)0x0) {
          return 0;
        }
        piVar5[1] = param_3;
        iVar2 = (*(code *)puVar1)(by_dir_hash_cmp);
        puVar1 = PTR_CRYPTO_malloc_006a8108;
        piVar5[2] = iVar2;
        iVar2 = (*(code *)puVar1)(pcVar7 + 1,"by_dir.c",0xfd);
        *piVar5 = iVar2;
        if (iVar2 == 0) {
LAB_00587dd4:
          if (piVar5[2] != 0) {
            (*(code *)PTR_sk_pop_free_006a8158)(piVar5[2],by_dir_hash_free);
          }
          (*(code *)PTR_CRYPTO_free_006a7f88)(piVar5);
          return 0;
        }
        if (piVar5[2] == 0) {
          (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
          goto LAB_00587dd4;
        }
        (*(code *)PTR_strncpy_006aaaec)(iVar2,param_2,pcVar7);
        puVar1 = PTR_sk_push_006a80a8;
        pcVar7[*piVar5] = '\0';
        iVar2 = (*(code *)puVar1)(*param_1,piVar5);
        if (iVar2 == 0) {
          if (*piVar5 != 0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
          }
          if (piVar5[2] != 0) {
            (*(code *)PTR_sk_pop_free_006a8158)(piVar5[2],by_dir_hash_free);
          }
          (*(code *)PTR_CRYPTO_free_006a7f88)(piVar5);
          return 0;
        }
        if (pcVar8[-1] == '\0') {
          return 1;
        }
      }
    }
    pcVar8 = pcVar8 + 1;
    param_2 = pcVar9;
  } while( true );
}

