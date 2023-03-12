
/* WARNING: Removing unreachable block (ram,0x00476ab4) */
/* WARNING: Removing unreachable block (ram,0x00476ad8) */
/* WARNING: Removing unreachable block (ram,0x00476afc) */
/* WARNING: Removing unreachable block (ram,0x00476b0c) */

int print_user_part_3(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  char **ppcVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  
  ppcVar2 = (char **)(*(code *)PTR_sk_value_006a7f24)
                               (*(undefined4 *)(*(int *)(param_1 + 4) + 4),param_3);
  puVar8 = (undefined4 *)PTR_bio_err_006a7f3c;
  iVar3 = (int)**ppcVar2;
  if (iVar3 != 0x49) {
    if (param_3 < 0) {
      iVar3 = get_index(param_1,ppcVar2[4],0x49);
      if ((-1 < iVar3) && (puVar8 = (undefined4 *)PTR_bio_err_006a7f3c, param_4 != 0)) {
LAB_00476cd4:
        puVar4 = (undefined4 *)
                 (*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(*(int *)(param_1 + 4) + 4),iVar3);
        (*(code *)PTR_BIO_printf_006a7f38)(param_2,"%s \"%s\"\n","g N entry",puVar4[3]);
        iVar3 = 0;
        do {
          uVar6 = *puVar4;
          iVar7 = iVar3 + 1;
          puVar4 = puVar4 + 1;
          iVar1 = (*(code *)PTR_BIO_printf_006a7f38)(*puVar8,"  %d = \"%s\"\n",iVar3,uVar6);
          iVar3 = iVar7;
        } while (iVar7 != 6);
        return iVar1;
      }
    }
    else {
      if (param_4 == 0) {
        pcVar5 = ppcVar2[4];
        if (pcVar5 == (char *)0x0) {
          return -1;
        }
        iVar3 = 0;
        puVar9 = &_gp;
        while( true ) {
          while( true ) {
            iVar1 = (**(code **)(puVar9 + -0x7fb4))(*(undefined4 *)(*(int *)(param_1 + 4) + 4));
            if (iVar1 <= iVar3) {
              return -1;
            }
            ppcVar2 = (char **)(**(code **)(puVar9 + -0x7fbc))
                                         (*(undefined4 *)(*(int *)(param_1 + 4) + 4),iVar3);
            if (**ppcVar2 == 'I') break;
            iVar3 = iVar3 + 1;
          }
          iVar1 = (**(code **)(puVar9 + -0x52c0))(pcVar5,ppcVar2[3]);
          if (iVar1 == 0) break;
          iVar3 = iVar3 + 1;
        }
        return iVar3;
      }
      puVar4 = (undefined4 *)
               (*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(*(int *)(param_1 + 4) + 4),param_3);
      (*(code *)PTR_BIO_printf_006a7f38)(param_2,"%s \"%s\"\n","User entry",puVar4[3]);
      iVar3 = 0;
      do {
        uVar6 = *puVar4;
        iVar1 = iVar3 + 1;
        puVar4 = puVar4 + 1;
        (*(code *)PTR_BIO_printf_006a7f38)(*puVar8,"  %d = \"%s\"\n",iVar3,uVar6);
        iVar3 = iVar1;
      } while (iVar1 != 6);
      iVar3 = get_index(param_1,ppcVar2[4],0x49);
      if (-1 < iVar3) goto LAB_00476cd4;
    }
  }
  return iVar3;
}

