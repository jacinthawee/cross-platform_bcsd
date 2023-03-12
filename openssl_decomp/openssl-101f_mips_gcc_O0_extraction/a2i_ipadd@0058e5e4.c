
int a2i_ipadd(uchar *ipout,char *ipasc)

{
  byte bVar1;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint *puVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  char *list;
  int iVar9;
  int iVar10;
  int iVar11;
  X509_NAME *name;
  uint *puVar12;
  uint *puVar13;
  byte *pbVar14;
  byte *pbVar15;
  uint *unaff_s2;
  undefined4 *unaff_s4;
  uint uStack_d8;
  uint uStack_d4;
  uint *puStack_d0;
  uint *puStack_cc;
  uint auStack_c8 [4];
  int iStack_b8;
  int iStack_b4;
  int iStack_b0;
  uint auStack_ac [4];
  undefined auStack_9c [16];
  X509_NAME *pXStack_8c;
  undefined *puStack_88;
  uint *puStack_84;
  uint *puStack_80;
  uchar *puStack_7c;
  undefined4 *puStack_78;
  uint local_48;
  uint local_44;
  uint local_40;
  uint *local_3c;
  undefined4 local_38 [4];
  uint *local_28;
  uint *local_24;
  int local_20;
  int local_1c;
  
  puStack_88 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar7 = (*(code *)PTR_strchr_006aab34)(ipasc,0x3a);
  if (iVar7 == 0) {
    puVar12 = &local_48;
    iVar7 = (*(code *)PTR___isoc99_sscanf_006aab10)(ipasc,"%d.%d.%d.%d",puVar12,&local_44);
    puVar13 = unaff_s2;
    if ((((iVar7 == 4) && (local_48 < 0x100)) && (local_44 < 0x100)) &&
       ((puVar12 = local_3c, local_40 < 0x100 && (local_3c < (uint *)0x100)))) {
      *ipout = (uchar)local_48;
      ipout[1] = (uchar)local_44;
      ipout[2] = (uchar)local_40;
      ipout[3] = (uchar)local_3c;
      goto LAB_0058e728;
    }
LAB_0058e724:
    local_3c = puVar12;
    iVar7 = 0;
    unaff_s2 = puVar13;
  }
  else {
    unaff_s4 = local_38;
    local_28 = (uint *)0x0;
    local_20 = 0;
    local_3c = (uint *)0x0;
    local_24 = (uint *)0xffffffff;
    iVar7 = CONF_parse_list(ipasc,0x3a,0,ipv6_cb,unaff_s4);
    puVar5 = local_24;
    unaff_s2 = local_28;
    puVar12 = local_3c;
    puVar13 = (uint *)0xffffffff;
    if (iVar7 == 0) goto LAB_0058e724;
    ipasc = (char *)local_24;
    puVar13 = local_28;
    if (local_24 != (uint *)0xffffffff) {
      if ((local_28 != (uint *)&SUB_00000010) && (local_20 < 4)) {
        if (local_20 != 3) {
          if (local_20 == 2) {
            if (local_24 != (uint *)0x0) {
              iVar7 = 0;
              if (local_24 == local_28) {
                local_3c = local_24;
                if ((int)local_24 < 0) goto LAB_0058e768;
                (*(code *)PTR_memcpy_006aabf4)(ipout,unaff_s4);
                local_3c = (uint *)(0x10 - (int)puVar5);
                (*(code *)PTR_memset_006aab00)(ipout + (int)puVar5,0);
                iVar7 = 0x10;
              }
              goto LAB_0058e728;
            }
LAB_0058e828:
            (*(code *)PTR_memcpy_006aabf4)(ipout,unaff_s4,local_24);
            local_3c = (uint *)(0x10 - (int)unaff_s2);
            (*(code *)PTR_memset_006aab00)(ipout + (int)puVar5,0);
            if (puVar5 == unaff_s2) {
              iVar7 = 0x10;
              goto LAB_0058e728;
            }
          }
          else {
            if ((local_24 == (uint *)0x0) || (local_24 == local_28)) goto LAB_0058e724;
            if ((int)local_24 < 0) goto LAB_0058e768;
            (*(code *)PTR_memcpy_006aabf4)(ipout,unaff_s4,local_24);
            (*(code *)PTR_memset_006aab00)(ipout + (int)puVar5,0,0x10 - (int)unaff_s2);
          }
          local_3c = (uint *)((int)unaff_s2 - (int)puVar5);
          (*(code *)PTR_memcpy_006aabf4)
                    (ipout + (int)((int)puVar5 + (0x10 - (int)unaff_s2)),
                     (char *)((int)unaff_s4 + (int)puVar5));
          iVar7 = 0x10;
          goto LAB_0058e728;
        }
        if ((int)local_28 < 1) {
          if ((int)local_24 < 0) goto LAB_0058e768;
          goto LAB_0058e828;
        }
      }
      goto LAB_0058e724;
    }
    if (local_28 != (uint *)&SUB_00000010) goto LAB_0058e724;
LAB_0058e768:
    *(undefined4 *)ipout = local_38[0];
    *(undefined4 *)(ipout + 4) = local_38[1];
    *(undefined4 *)(ipout + 8) = local_38[2];
    *(undefined4 *)(ipout + 0xc) = local_38[3];
    iVar7 = 0x10;
  }
LAB_0058e728:
  if (local_1c == *(int *)puStack_88) {
    return iVar7;
  }
  iVar7 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar4 = PTR___stack_chk_guard_006aabf0;
  puVar12 = (uint *)0x2f;
  pXStack_8c = *(X509_NAME **)PTR___stack_chk_guard_006aabf0;
  puStack_84 = (uint *)ipasc;
  puStack_80 = unaff_s2;
  puStack_7c = ipout;
  puStack_78 = unaff_s4;
  iVar8 = (*(code *)PTR_strchr_006aab34)();
  if ((iVar8 == 0) ||
     (list = (char *)(*(code *)PTR_BUF_strdup_006a80dc)(iVar7), puVar3 = PTR_strchr_006aab34,
     list == (char *)0x0)) {
LAB_0058ea6c:
    puVar13 = puVar12;
    iVar7 = 0;
  }
  else {
    list[iVar8 - iVar7] = '\0';
    iVar9 = (*(code *)puVar3)(list,0x3a);
    if (iVar9 == 0) {
      local_3c = &uStack_d8;
      puVar13 = (uint *)0x66f590;
      iVar9 = (*(code *)PTR___isoc99_sscanf_006aab10)
                        (list,"%d.%d.%d.%d",local_3c,&uStack_d4,&puStack_d0,&puStack_cc);
      if ((((iVar9 == 4) && (uStack_d8 < 0x100)) && (puVar13 = puStack_d0, uStack_d4 < 0x100)) &&
         ((local_3c = puStack_cc, puStack_d0 < (uint *)0x100 &&
          (iVar11 = 4, puStack_cc < (uint *)0x100)))) {
        auStack_ac[0] =
             (uint)puStack_cc & 0xff |
             (uint)CONCAT21(CONCAT11((char)uStack_d8,(char)uStack_d4),(char)puStack_d0) << 8;
LAB_0058ea38:
        puVar13 = auStack_ac;
        puVar12 = (uint *)(list + (iVar8 - iVar7) + 1);
        iVar7 = a2i_ipadd((uchar *)((int)puVar13 + iVar11),(char *)puVar12);
        (*(code *)PTR_CRYPTO_free_006a7f88)(list);
        local_3c = puStack_cc;
        if (((iVar7 != 0) && (iVar7 == iVar9)) &&
           (iVar7 = (*(code *)PTR_ASN1_OCTET_STRING_new_006a978c)(), local_3c = puStack_cc,
           iVar7 != 0)) {
          local_3c = (uint *)(iVar9 << 1);
          iVar8 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(iVar7,puVar13);
          if (iVar8 == 0) {
            (*(code *)PTR_ASN1_OCTET_STRING_free_006a9e1c)(iVar7);
            iVar7 = 0;
          }
          goto LAB_0058ead4;
        }
        goto LAB_0058ea6c;
      }
    }
    else {
      iStack_b8 = 0;
      iStack_b0 = 0;
      puStack_cc = (uint *)0x0;
      iStack_b4 = -1;
      puVar13 = (uint *)&DAT_0000003a;
      iVar10 = CONF_parse_list(list,0x3a,0,ipv6_cb,auStack_c8);
      iVar11 = iStack_b4;
      iVar9 = iStack_b8;
      local_3c = puStack_cc;
      if (iVar10 != 0) {
        if (iStack_b4 == -1) {
          if (iStack_b8 == 0x10) {
LAB_0058eb1c:
            auStack_ac[0] = auStack_c8[0];
LAB_0058ea34:
            iVar11 = 0x10;
            iVar9 = 0x10;
            goto LAB_0058ea38;
          }
        }
        else if ((iStack_b8 != 0x10) && (iStack_b0 < 4)) {
          if (iStack_b0 == 3) {
            if (iStack_b8 < 1) {
              if (iStack_b4 < 0) goto LAB_0058eb1c;
LAB_0058ebd8:
              (*(code *)PTR___memcpy_chk_006aab54)(auStack_ac,auStack_c8,iStack_b4,0x20);
              puStack_cc = (uint *)(0x10 - iVar9);
              (*(code *)PTR_memset_006aab00)((int)auStack_ac + iVar11,0);
              if (iVar11 == iVar9) goto LAB_0058ea34;
LAB_0058ea18:
              puStack_cc = (uint *)(iVar9 - iVar11);
              (*(code *)PTR_memcpy_006aabf4)(auStack_9c + (iVar11 - iVar9),(int)auStack_c8 + iVar11)
              ;
              goto LAB_0058ea34;
            }
          }
          else if (iStack_b0 == 2) {
            if (iStack_b4 == 0) goto LAB_0058ebd8;
            if (iStack_b4 == iStack_b8) {
              if (iStack_b4 < 0) goto LAB_0058eb1c;
              (*(code *)PTR___memcpy_chk_006aab54)(auStack_ac,auStack_c8,iStack_b4,0x20);
              puStack_cc = (uint *)(0x10 - iVar11);
              (*(code *)PTR_memset_006aab00)((int)auStack_ac + iVar11,0);
              goto LAB_0058ea34;
            }
          }
          else if ((iStack_b4 != 0) && (iStack_b4 != iStack_b8)) {
            if (iStack_b4 < 0) goto LAB_0058eb1c;
            (*(code *)PTR___memcpy_chk_006aab54)(auStack_ac,auStack_c8,iStack_b4,0x20);
            (*(code *)PTR_memset_006aab00)((int)auStack_ac + iVar11,0,0x10 - iVar9);
            goto LAB_0058ea18;
          }
        }
      }
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(list);
    iVar7 = 0;
  }
LAB_0058ead4:
  if (pXStack_8c == *(X509_NAME **)puVar4) {
    return iVar7;
  }
  name = pXStack_8c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (name == (X509_NAME *)0x0) {
    return 0;
  }
  iVar8 = 0;
  iVar7 = (*(code *)PTR_sk_num_006a7f2c)(puVar13);
  if (0 < iVar7) {
    do {
      iVar7 = (*(code *)PTR_sk_value_006a7f24)(puVar13,iVar8);
      pbVar14 = *(byte **)(iVar7 + 4);
      bVar1 = *pbVar14;
      if (bVar1 == 0) goto LAB_0058ed54;
      if ((bVar1 == 0x3a) || (pbVar6 = pbVar14, (bVar1 & 0xfd) == 0x2c)) {
        iVar9 = 0;
        pbVar15 = pbVar14;
        if ((pbVar14[1] != 0) && (pbVar15 = pbVar14 + 1, pbVar14[1] == 0x2b)) {
          pbVar15 = pbVar14 + 2;
          goto LAB_0058edd4;
        }
      }
      else {
        do {
          pbVar15 = pbVar6;
          bVar2 = pbVar15[1];
          if (bVar2 == 0) goto LAB_0058ed4c;
        } while ((bVar2 != 0x3a) && (pbVar6 = pbVar15 + 1, (bVar2 & 0xfd) != 0x2c));
        if (pbVar15[2] == 0) {
LAB_0058ed4c:
          if (bVar1 != 0x2b) {
LAB_0058ed54:
            iVar9 = 0;
            pbVar15 = pbVar14;
            goto LAB_0058ed58;
          }
          pbVar15 = pbVar14 + 1;
        }
        else {
          pbVar14 = pbVar15 + 2;
          if (pbVar15[2] != 0x2b) goto LAB_0058ed54;
          pbVar15 = pbVar15 + 3;
        }
LAB_0058edd4:
        iVar9 = -1;
      }
LAB_0058ed58:
      iVar7 = X509_NAME_add_entry_by_txt
                        (name,(char *)pbVar15,(int)local_3c,*(uchar **)(iVar7 + 8),-1,-1,iVar9);
      if (iVar7 == 0) {
        return 0;
      }
      iVar8 = iVar8 + 1;
      iVar7 = (*(code *)PTR_sk_num_006a7f2c)(puVar13);
    } while (iVar8 < iVar7);
  }
  return 1;
}

