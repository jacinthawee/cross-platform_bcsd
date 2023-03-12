
int ipv6_cb(byte *param_1,byte *param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  X509_NAME_ENTRY *ne;
  ASN1_STRING *pAVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  X509_NAME *name;
  uchar *puVar9;
  int iVar10;
  undefined *puVar11;
  uint local_24;
  uint local_20;
  byte *local_1c;
  uint local_18;
  X509_NAME *local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar10 = *(int *)(param_3 + 0x10);
  local_14 = *(X509_NAME **)PTR___stack_chk_guard_006aabf0;
  iVar2 = 0;
  if (iVar10 == 0x10) goto LAB_0058bfac;
  if (param_2 == (byte *)0x0) {
    if (*(int *)(param_3 + 0x14) == -1) {
      *(int *)(param_3 + 0x14) = iVar10;
    }
    else if (iVar10 != *(int *)(param_3 + 0x14)) goto LAB_0058bfa8;
    iVar2 = 1;
    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;
  }
  else {
    if ((int)param_2 < 5) {
      uVar7 = 0;
      do {
        uVar6 = (uint)*param_1;
        uVar8 = uVar6 - 0x30;
        if (9 < (uVar8 & 0xff)) {
          if (uVar6 - 0x41 < 6) {
            uVar8 = uVar6 - 0x37;
          }
          else {
            uVar8 = uVar6 - 0x57;
            if (5 < uVar6 - 0x61) goto LAB_0058bfa8;
          }
        }
        param_2 = param_2 + -1;
        uVar7 = uVar8 | uVar7 << 4;
        param_1 = param_1 + 1;
      } while (param_2 != (byte *)0x0);
      iVar2 = 1;
      *(undefined *)(param_3 + iVar10) = (char)(uVar7 >> 8);
      ((undefined *)(param_3 + iVar10))[1] = (char)uVar7;
      *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 2;
      goto LAB_0058bfac;
    }
    iVar2 = 0;
    if (0xc < iVar10) goto LAB_0058bfac;
    param_2 = param_1 + (int)param_2;
    iVar2 = 0;
    if (*param_2 != 0) goto LAB_0058bfac;
    param_2 = (byte *)0x66f590;
    iVar2 = (*(code *)PTR___isoc99_sscanf_006aab10)
                      (param_1,"%d.%d.%d.%d",&local_24,&local_20,&local_1c,&local_18);
    if ((iVar2 == 4) && (local_24 < 0x100)) {
      iVar2 = 0;
      if (0xff < local_20) goto LAB_0058bfac;
      param_2 = local_1c;
      if ((local_1c < (byte *)0x100) &&
         (puVar11 = (undefined *)(param_3 + iVar10), local_18 < 0x100)) {
        iVar2 = 1;
        *puVar11 = (char)local_24;
        puVar11[1] = (char)local_20;
        puVar11[2] = (char)local_1c;
        puVar11[3] = (char)local_18;
        *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 4;
        goto LAB_0058bfac;
      }
    }
LAB_0058bfa8:
    iVar2 = 0;
  }
LAB_0058bfac:
  if (local_14 == *(X509_NAME **)puVar1) {
    return iVar2;
  }
  name = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar10 = 0;
  iVar2 = -1;
  do {
    do {
      iVar2 = X509_NAME_get_index_by_NID(name,0x30,iVar2);
      if (iVar2 < 0) {
        iVar4 = 0;
        iVar2 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
        if (iVar2 < 1) {
          return iVar10;
        }
        goto LAB_0058c2b0;
      }
      ne = X509_NAME_get_entry(name,iVar2);
      pAVar3 = X509_NAME_ENTRY_get_data(ne);
    } while (((pAVar3->type != 0x16) || (puVar9 = pAVar3->data, puVar9 == (uchar *)0x0)) ||
            (pAVar3->length == 0));
    if (iVar10 == 0) {
      iVar10 = (*(code *)PTR_sk_new_006a91b4)(sk_strcmp);
      if (iVar10 == 0) {
        return 0;
      }
      puVar9 = pAVar3->data;
    }
    iVar4 = (*(code *)PTR_sk_find_006a906c)(iVar10,puVar9);
  } while ((iVar4 != -1) ||
          ((iVar4 = (*(code *)PTR_BUF_strdup_006a80dc)(pAVar3->data), iVar4 != 0 &&
           (iVar4 = (*(code *)PTR_sk_push_006a80a8)(iVar10,iVar4), iVar4 != 0))));
LAB_0058c23c:
  (*(code *)PTR_sk_pop_free_006a8158)(iVar10,str_free);
  return 0;
LAB_0058c2b0:
  piVar5 = (int *)(*(code *)PTR_sk_value_006a7f24)(param_2,iVar4);
  if ((((*piVar5 == 1) && (piVar5 = (int *)piVar5[1], piVar5[1] == 0x16)) &&
      (iVar2 = piVar5[2], iVar2 != 0)) && (*piVar5 != 0)) {
    if (iVar10 == 0) {
      iVar10 = (*(code *)PTR_sk_new_006a91b4)(sk_strcmp);
      if (iVar10 == 0) {
        return 0;
      }
      iVar2 = piVar5[2];
    }
    iVar2 = (*(code *)PTR_sk_find_006a906c)(iVar10,iVar2);
    if ((iVar2 == -1) &&
       ((iVar2 = (*(code *)PTR_BUF_strdup_006a80dc)(piVar5[2]), iVar2 == 0 ||
        (iVar2 = (*(code *)PTR_sk_push_006a80a8)(iVar10,iVar2), iVar2 == 0)))) goto LAB_0058c23c;
  }
  iVar4 = iVar4 + 1;
  iVar2 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
  if (iVar2 <= iVar4) {
    return iVar10;
  }
  goto LAB_0058c2b0;
}

