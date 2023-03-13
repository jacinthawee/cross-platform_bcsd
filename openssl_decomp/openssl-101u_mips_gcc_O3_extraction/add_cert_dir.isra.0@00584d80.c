
undefined4 add_cert_dir_isra_0(int *param_1,char *param_2,int param_3)

{
  undefined *puVar1;
  char cVar5;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  undefined4 uVar12;
  
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    cVar5 = *param_2;
    pcVar11 = param_2 + 1;
    pcVar9 = param_2;
    pcVar10 = param_2;
    if (cVar5 == ':') goto LAB_00584f54;
LAB_00584df8:
    iVar8 = (int)param_2 - (int)pcVar9;
    if (cVar5 != '\0') goto LAB_00584f44;
    pcVar10 = pcVar9;
    pcVar9 = pcVar11;
    if (iVar8 == 0) {
      return 1;
    }
    do {
      iVar7 = 0;
      iVar2 = (*(code *)PTR_sk_num_006a6e2c)(*param_1);
      if (0 < iVar2) {
        do {
          puVar3 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(*param_1,iVar7);
          uVar12 = *puVar3;
          iVar2 = (*(code *)PTR_strlen_006a9a24)(uVar12);
          if ((iVar2 == iVar8) &&
             (iVar2 = (*(code *)PTR_strncmp_006a9970)(uVar12,pcVar10,iVar8), iVar2 == 0)) break;
          iVar7 = iVar7 + 1;
          iVar2 = (*(code *)PTR_sk_num_006a6e2c)(*param_1);
        } while (iVar7 < iVar2);
      }
      iVar2 = (*(code *)PTR_sk_num_006a6e2c)(*param_1);
      if (iVar2 <= iVar7) {
        if (*param_1 == 0) {
          iVar2 = (*(code *)PTR_sk_new_null_006a6fa4)();
          *param_1 = iVar2;
          if (iVar2 == 0) {
            uVar6 = 0x41;
            uVar12 = 0xe5;
            goto LAB_00584fd4;
          }
        }
        piVar4 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0xc,"by_dir.c",0xe9);
        puVar1 = PTR_sk_new_006a806c;
        if (piVar4 == (int *)0x0) {
          return 0;
        }
        piVar4[1] = param_3;
        iVar2 = (*(code *)puVar1)(by_dir_hash_cmp);
        piVar4[2] = iVar2;
        iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar8 + 1,"by_dir.c",0xee);
        *piVar4 = iVar2;
        if (iVar2 == 0) {
LAB_00585054:
          if (piVar4[2] != 0) {
            (*(code *)PTR_sk_pop_free_006a7058)(piVar4[2],by_dir_hash_free);
          }
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar4);
          return 0;
        }
        if (piVar4[2] == 0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
          goto LAB_00585054;
        }
        (*(code *)PTR_strncpy_006a99e0)(iVar2,pcVar10,iVar8);
        puVar1 = PTR_sk_push_006a6fa8;
        *(undefined *)(*piVar4 + iVar8) = 0;
        iVar8 = (*(code *)puVar1)(*param_1,piVar4);
        if (iVar8 == 0) {
          if (*piVar4 != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
          }
          if (piVar4[2] != 0) {
            (*(code *)PTR_sk_pop_free_006a7058)(piVar4[2],by_dir_hash_free);
          }
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar4);
          return 0;
        }
      }
      pcVar11 = pcVar9;
      if (*param_2 == '\0') {
        return 1;
      }
LAB_00584f44:
      do {
        param_2 = param_2 + 1;
        cVar5 = *param_2;
        pcVar11 = pcVar11 + 1;
        pcVar10 = pcVar9;
        if (cVar5 != ':') goto LAB_00584df8;
LAB_00584f54:
        pcVar9 = pcVar11;
        iVar8 = (int)param_2 - (int)pcVar10;
        pcVar11 = pcVar9;
      } while (iVar8 == 0);
    } while( true );
  }
  uVar6 = 0x71;
  uVar12 = 0xcc;
LAB_00584fd4:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xb,100,uVar6,"by_dir.c",uVar12);
  return 0;
}

