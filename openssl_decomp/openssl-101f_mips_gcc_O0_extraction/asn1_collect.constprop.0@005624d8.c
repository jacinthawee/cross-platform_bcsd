
uint asn1_collect_constprop_0(int *param_1,uchar **param_2,int param_3,uint param_4,int param_5)

{
  undefined *puVar1;
  uchar *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uchar *local_40;
  int iStack_3c;
  int iStack_38;
  int local_34;
  uchar *local_30;
  uint local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  param_4 = param_4 & 1;
  local_40 = *param_2;
  local_2c = *(uint *)PTR___stack_chk_guard_006aabf0;
  if (param_1 == (int *)0x0) {
    if (param_4 == 0) {
      uVar8 = 1;
      *param_2 = local_40 + param_3;
      goto LAB_00562720;
    }
    if (0 < param_3) goto LAB_00562550;
  }
  else {
    if (0 < param_3) {
LAB_00562550:
LAB_005625b0:
      do {
        puVar2 = local_40;
        if (((param_3 != 1) && (*local_40 == '\0')) && (local_40[1] == '\0')) {
          local_40 = local_40 + 2;
          if (param_4 != 0) goto LAB_00562784;
          uVar6 = 0x9f;
          uVar4 = 0x49c;
          goto LAB_005626a8;
        }
        local_30 = local_40;
        uVar3 = ASN1_get_object(&local_30,&local_34,&iStack_3c,&iStack_38,param_3);
        uVar8 = uVar3 & 0x80;
        if (uVar8 != 0) {
          uVar8 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,0x66,s_tasn_dec_c_0066ab0c,0x51a);
          (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x6a,0x3a,s_tasn_dec_c_0066ab0c,0x4a6);
          goto LAB_00562720;
        }
        local_40 = local_30;
        iVar7 = local_34;
        if ((uVar3 & 1) != 0) {
          iVar7 = param_3 - ((int)local_30 - (int)puVar2);
        }
        if ((uVar3 & 0x20) == 0) {
          if (iVar7 != 0) {
            if (param_1 != (int *)0x0) {
              iVar5 = *param_1;
              uVar8 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(param_1,iVar5 + iVar7);
              if (uVar8 == 0) {
                (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x8c,0x41,s_tasn_dec_c_0066ab0c,0x4cc);
                goto LAB_00562720;
              }
              (*(code *)PTR_memcpy_006aabf4)(param_1[1] + iVar5,local_40,iVar7);
            }
            local_40 = local_40 + iVar7;
            param_3 = param_3 - ((int)local_40 - (int)puVar2);
            if (param_3 < 1) break;
            goto LAB_005625b0;
          }
        }
        else {
          if (4 < param_5) {
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x6a,0xc5,s_tasn_dec_c_0066ab0c,0x4b0);
            goto LAB_00562720;
          }
          uVar8 = asn1_collect_constprop_0(param_1,&local_40,iVar7,(byte)uVar3 & 1,param_5 + 1);
          if (uVar8 == 0) goto LAB_00562720;
        }
        param_3 = param_3 - ((int)local_40 - (int)puVar2);
      } while (0 < param_3);
    }
    if (param_4 == 0) {
LAB_00562784:
      uVar8 = 1;
      *param_2 = local_40;
      goto LAB_00562720;
    }
  }
  uVar6 = 0x89;
  uVar4 = 0x4bd;
LAB_005626a8:
  uVar8 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x6a,uVar6,s_tasn_dec_c_0066ab0c,uVar4);
LAB_00562720:
  if (local_2c == *(uint *)puVar1) {
    return uVar8;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (0x1e < local_2c) {
    return 0;
  }
  return *(uint *)(tag2bit + local_2c * 4);
}

