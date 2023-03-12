
ASN1_OCTET_STRING * a2i_IPADDRESS(char *ipasc)

{
  byte bVar1;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint *puVar5;
  byte *pbVar6;
  int iVar7;
  ASN1_OCTET_STRING *pAVar8;
  int iVar9;
  char *list;
  int iVar10;
  int iVar11;
  int iVar12;
  X509_NAME *name;
  uint *puVar13;
  uint *puVar14;
  byte *pbVar15;
  byte *pbVar16;
  uint *unaff_s3;
  uint *unaff_s4;
  uint uStack_150;
  uint uStack_14c;
  uint *puStack_148;
  uint *puStack_144;
  uint auStack_140 [4];
  int iStack_130;
  int iStack_12c;
  int iStack_128;
  uint auStack_124 [4];
  undefined auStack_114 [16];
  X509_NAME *pXStack_104;
  undefined *puStack_100;
  uint *puStack_fc;
  uint *puStack_f8;
  uint *puStack_f4;
  uint *puStack_f0;
  uint uStack_c0;
  uint uStack_bc;
  uint uStack_b8;
  uint *puStack_b4;
  uint auStack_b0 [4];
  uint *puStack_a0;
  uint *puStack_9c;
  int iStack_98;
  int iStack_94;
  ASN1_OCTET_STRING *pAStack_90;
  undefined *puStack_8c;
  uint *puStack_88;
  uint *puStack_84;
  uint *puStack_80;
  code *pcStack_7c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint *local_4c;
  uint local_48 [4];
  uint *local_38;
  uint *local_34;
  int local_30;
  uint local_2c [4];
  uint *local_1c;
  
  puStack_8c = PTR___stack_chk_guard_006aabf0;
  local_1c = *(uint **)PTR___stack_chk_guard_006aabf0;
  iVar7 = (*(code *)PTR_strchr_006aab34)(ipasc,0x3a);
  if (iVar7 == 0) {
    puStack_fc = (uint *)0x66f5b0;
    ipasc = (char *)(*(code *)PTR___isoc99_sscanf_006aab10)(ipasc,"%d.%d.%d.%d",&local_58,&local_54)
    ;
    if ((((ipasc != &SUB_00000004) || (0xff < local_58)) || (0xff < local_54)) ||
       ((puStack_fc = local_4c, 0xff < local_50 || ((uint *)0xff < local_4c)))) goto LAB_0058e44c;
    local_2c[0] = (uint)local_4c & 0xff |
                  (uint)CONCAT21(CONCAT11((char)local_58,(char)local_54),(char)local_50) << 8;
LAB_0058e3f8:
    pAVar8 = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_OCTET_STRING_new_006a978c)();
    puStack_fc = local_4c;
    if (pAVar8 == (ASN1_OCTET_STRING *)0x0) goto LAB_0058e44c;
    puStack_fc = local_2c;
    iVar7 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(pAVar8,puStack_fc,ipasc);
    pAStack_90 = pAVar8;
    if (iVar7 == 0) {
      pAStack_90 = (ASN1_OCTET_STRING *)0x0;
      (*(code *)PTR_ASN1_OCTET_STRING_free_006a9e1c)(pAVar8);
    }
  }
  else {
    unaff_s3 = local_48;
    local_38 = (uint *)0x0;
    local_30 = 0;
    local_34 = (uint *)0xffffffff;
    local_4c = (uint *)&DAT_0000003a;
    iVar7 = CONF_parse_list(ipasc,0x3a,0,ipv6_cb,unaff_s3);
    puVar14 = local_34;
    puVar13 = local_38;
    puStack_fc = local_4c;
    if (iVar7 != 0) {
      ipasc = (char *)local_34;
      if (local_34 == (uint *)0xffffffff) {
        if (local_38 == (uint *)&SUB_00000010) {
LAB_0058e494:
          local_2c[0] = local_48[0];
LAB_0058e3f4:
          ipasc = &SUB_00000010;
          goto LAB_0058e3f8;
        }
      }
      else if ((local_38 != (uint *)&SUB_00000010) && (local_30 < 4)) {
        if (local_30 == 3) {
          if ((int)local_38 < 1) {
            if ((int)local_34 < 0) goto LAB_0058e494;
LAB_0058e544:
            unaff_s4 = local_2c;
            (*(code *)PTR___memcpy_chk_006aab54)(unaff_s4,unaff_s3,local_34,0x10);
            local_4c = (uint *)0x0;
            (*(code *)PTR_memset_006aab00)
                      ((char *)((int)unaff_s4 + (int)puVar14),0,0x10 - (int)puVar13);
            if (puVar14 == puVar13) goto LAB_0058e3f4;
LAB_0058e3d8:
            unaff_s4 = local_2c;
            local_4c = (uint *)((int)unaff_s3 + (int)puVar14);
            (*(code *)PTR_memcpy_006aabf4)
                      ((char *)((int)unaff_s4 + (int)((int)puVar14 + (0x10 - (int)puVar13))),
                       local_4c,(int)puVar13 - (int)puVar14);
            goto LAB_0058e3f4;
          }
        }
        else if (local_30 == 2) {
          if (local_34 == (uint *)0x0) goto LAB_0058e544;
          if (local_34 == local_38) {
            if ((int)local_34 < 0) goto LAB_0058e494;
            iVar7 = (*(code *)PTR___memcpy_chk_006aab54)(local_2c,unaff_s3,local_34,0x10);
            local_4c = (uint *)0x0;
            (*(code *)PTR_memset_006aab00)((char *)(iVar7 + (int)puVar14),0,0x10 - (int)puVar14);
            goto LAB_0058e3f4;
          }
        }
        else if ((local_34 != (uint *)0x0) && (local_34 != local_38)) {
          if ((int)local_34 < 0) goto LAB_0058e494;
          (*(code *)PTR___memcpy_chk_006aab54)(local_2c,unaff_s3,local_34,0x10);
          (*(code *)PTR_memset_006aab00)
                    ((char *)((int)local_2c + (int)puVar14),0,0x10 - (int)puVar13);
          goto LAB_0058e3d8;
        }
      }
    }
LAB_0058e44c:
    pAStack_90 = (ASN1_OCTET_STRING *)0x0;
  }
  if (local_1c == *(uint **)puStack_8c) {
    return pAStack_90;
  }
  pcStack_7c = a2i_ipadd;
  puStack_f4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_100 = PTR___stack_chk_guard_006aabf0;
  iStack_94 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_88 = (uint *)ipasc;
  puStack_84 = unaff_s3;
  puStack_80 = unaff_s4;
  iVar7 = (*(code *)PTR_strchr_006aab34)(puStack_fc,0x3a);
  if (iVar7 == 0) {
    puVar13 = &uStack_c0;
    pAVar8 = (ASN1_OCTET_STRING *)
             (*(code *)PTR___isoc99_sscanf_006aab10)(puStack_fc,"%d.%d.%d.%d",puVar13,&uStack_bc);
    if ((((pAVar8 == (ASN1_OCTET_STRING *)&SUB_00000004) && (uStack_c0 < 0x100)) &&
        (uStack_bc < 0x100)) &&
       ((puVar13 = puStack_b4, uStack_b8 < 0x100 && (puStack_b4 < (uint *)0x100)))) {
      *(char *)puStack_f4 = (char)uStack_c0;
      *(char *)((int)puStack_f4 + 1) = (char)uStack_bc;
      *(char *)((int)puStack_f4 + 2) = (char)uStack_b8;
      *(char *)((int)puStack_f4 + 3) = (char)puStack_b4;
      goto LAB_0058e728;
    }
LAB_0058e724:
    puStack_b4 = puVar13;
    pAVar8 = (ASN1_OCTET_STRING *)0x0;
  }
  else {
    unaff_s4 = auStack_b0;
    puStack_a0 = (uint *)0x0;
    iStack_98 = 0;
    puStack_b4 = (uint *)0x0;
    puStack_9c = (uint *)0xffffffff;
    iVar7 = CONF_parse_list((char *)puStack_fc,0x3a,0,ipv6_cb,unaff_s4);
    puVar5 = puStack_9c;
    puVar14 = puStack_a0;
    puVar13 = puStack_b4;
    ipasc = (char *)(uint *)0xffffffff;
    if (iVar7 == 0) goto LAB_0058e724;
    puStack_fc = puStack_9c;
    ipasc = (char *)puStack_a0;
    if (puStack_9c != (uint *)0xffffffff) {
      if ((puStack_a0 != (uint *)&SUB_00000010) && (iStack_98 < 4)) {
        if (iStack_98 != 3) {
          if (iStack_98 == 2) {
            if (puStack_9c != (uint *)0x0) {
              pAVar8 = (ASN1_OCTET_STRING *)0x0;
              if (puStack_9c == puStack_a0) {
                puStack_b4 = puStack_9c;
                if ((int)puStack_9c < 0) goto LAB_0058e768;
                (*(code *)PTR_memcpy_006aabf4)(puStack_f4,unaff_s4);
                puStack_b4 = (uint *)(0x10 - (int)puVar5);
                (*(code *)PTR_memset_006aab00)((char *)((int)puStack_f4 + (int)puVar5),0);
                pAVar8 = (ASN1_OCTET_STRING *)&SUB_00000010;
              }
              goto LAB_0058e728;
            }
LAB_0058e828:
            (*(code *)PTR_memcpy_006aabf4)(puStack_f4,unaff_s4,puStack_9c);
            puStack_b4 = (uint *)(0x10 - (int)puVar14);
            (*(code *)PTR_memset_006aab00)((char *)((int)puStack_f4 + (int)puVar5),0);
            if (puVar5 == puVar14) {
              pAVar8 = (ASN1_OCTET_STRING *)&SUB_00000010;
              goto LAB_0058e728;
            }
          }
          else {
            if ((puStack_9c == (uint *)0x0) || (puStack_9c == puStack_a0)) goto LAB_0058e724;
            if ((int)puStack_9c < 0) goto LAB_0058e768;
            (*(code *)PTR_memcpy_006aabf4)(puStack_f4,unaff_s4,puStack_9c);
            (*(code *)PTR_memset_006aab00)
                      ((char *)((int)puStack_f4 + (int)puVar5),0,0x10 - (int)puVar14);
          }
          puStack_b4 = (uint *)((int)puVar14 - (int)puVar5);
          (*(code *)PTR_memcpy_006aabf4)
                    ((char *)((int)puStack_f4 + (int)((int)puVar5 + (0x10 - (int)puVar14))),
                     (char *)((int)unaff_s4 + (int)puVar5));
          pAVar8 = (ASN1_OCTET_STRING *)&SUB_00000010;
          goto LAB_0058e728;
        }
        if ((int)puStack_a0 < 1) {
          if ((int)puStack_9c < 0) goto LAB_0058e768;
          goto LAB_0058e828;
        }
      }
      goto LAB_0058e724;
    }
    if (puStack_a0 != (uint *)&SUB_00000010) goto LAB_0058e724;
LAB_0058e768:
    *puStack_f4 = auStack_b0[0];
    puStack_f4[1] = auStack_b0[1];
    puStack_f4[2] = auStack_b0[2];
    puStack_f4[3] = auStack_b0[3];
    pAVar8 = (ASN1_OCTET_STRING *)&SUB_00000010;
  }
LAB_0058e728:
  if (iStack_94 == *(int *)puStack_100) {
    return pAVar8;
  }
  iVar7 = iStack_94;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar4 = PTR___stack_chk_guard_006aabf0;
  puVar13 = (uint *)0x2f;
  pXStack_104 = *(X509_NAME **)PTR___stack_chk_guard_006aabf0;
  puStack_f8 = (uint *)ipasc;
  puStack_f0 = unaff_s4;
  iVar9 = (*(code *)PTR_strchr_006aab34)();
  if ((iVar9 == 0) ||
     (list = (char *)(*(code *)PTR_BUF_strdup_006a80dc)(iVar7), puVar3 = PTR_strchr_006aab34,
     list == (char *)0x0)) {
LAB_0058ea6c:
    puVar14 = puVar13;
    pAVar8 = (ASN1_OCTET_STRING *)0x0;
  }
  else {
    list[iVar9 - iVar7] = '\0';
    iVar10 = (*(code *)puVar3)(list,0x3a);
    if (iVar10 == 0) {
      puStack_b4 = &uStack_150;
      puVar14 = (uint *)0x66f5b0;
      iVar10 = (*(code *)PTR___isoc99_sscanf_006aab10)
                         (list,"%d.%d.%d.%d",puStack_b4,&uStack_14c,&puStack_148,&puStack_144);
      if ((((iVar10 == 4) && (uStack_150 < 0x100)) && (puVar14 = puStack_148, uStack_14c < 0x100))
         && ((puStack_b4 = puStack_144, puStack_148 < (uint *)0x100 &&
             (iVar12 = 4, puStack_144 < (uint *)0x100)))) {
        auStack_124[0] =
             (uint)puStack_144 & 0xff |
             (uint)CONCAT21(CONCAT11((char)uStack_150,(char)uStack_14c),(char)puStack_148) << 8;
LAB_0058ea38:
        puVar14 = auStack_124;
        puVar13 = (uint *)(list + (iVar9 - iVar7) + 1);
        iVar7 = a2i_ipadd((uchar *)((int)puVar14 + iVar12),(char *)puVar13);
        (*(code *)PTR_CRYPTO_free_006a7f88)(list);
        puStack_b4 = puStack_144;
        if (((iVar7 != 0) && (iVar7 == iVar10)) &&
           (pAVar8 = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_OCTET_STRING_new_006a978c)(),
           puStack_b4 = puStack_144, pAVar8 != (ASN1_OCTET_STRING *)0x0)) {
          puStack_b4 = (uint *)(iVar10 << 1);
          iVar7 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(pAVar8,puVar14);
          if (iVar7 == 0) {
            (*(code *)PTR_ASN1_OCTET_STRING_free_006a9e1c)(pAVar8);
            pAVar8 = (ASN1_OCTET_STRING *)0x0;
          }
          goto LAB_0058ead4;
        }
        goto LAB_0058ea6c;
      }
    }
    else {
      iStack_130 = 0;
      iStack_128 = 0;
      puStack_144 = (uint *)0x0;
      iStack_12c = -1;
      puVar14 = (uint *)&DAT_0000003a;
      iVar11 = CONF_parse_list(list,0x3a,0,ipv6_cb,auStack_140);
      iVar12 = iStack_12c;
      iVar10 = iStack_130;
      puStack_b4 = puStack_144;
      if (iVar11 != 0) {
        if (iStack_12c == -1) {
          if (iStack_130 == 0x10) {
LAB_0058eb1c:
            auStack_124[0] = auStack_140[0];
LAB_0058ea34:
            iVar12 = 0x10;
            iVar10 = 0x10;
            goto LAB_0058ea38;
          }
        }
        else if ((iStack_130 != 0x10) && (iStack_128 < 4)) {
          if (iStack_128 == 3) {
            if (iStack_130 < 1) {
              if (iStack_12c < 0) goto LAB_0058eb1c;
LAB_0058ebd8:
              (*(code *)PTR___memcpy_chk_006aab54)(auStack_124,auStack_140,iStack_12c,0x20);
              puStack_144 = (uint *)(0x10 - iVar10);
              (*(code *)PTR_memset_006aab00)((int)auStack_124 + iVar12,0);
              if (iVar12 == iVar10) goto LAB_0058ea34;
LAB_0058ea18:
              puStack_144 = (uint *)(iVar10 - iVar12);
              (*(code *)PTR_memcpy_006aabf4)
                        (auStack_114 + (iVar12 - iVar10),(int)auStack_140 + iVar12);
              goto LAB_0058ea34;
            }
          }
          else if (iStack_128 == 2) {
            if (iStack_12c == 0) goto LAB_0058ebd8;
            if (iStack_12c == iStack_130) {
              if (iStack_12c < 0) goto LAB_0058eb1c;
              (*(code *)PTR___memcpy_chk_006aab54)(auStack_124,auStack_140,iStack_12c,0x20);
              puStack_144 = (uint *)(0x10 - iVar12);
              (*(code *)PTR_memset_006aab00)((int)auStack_124 + iVar12,0);
              goto LAB_0058ea34;
            }
          }
          else if ((iStack_12c != 0) && (iStack_12c != iStack_130)) {
            if (iStack_12c < 0) goto LAB_0058eb1c;
            (*(code *)PTR___memcpy_chk_006aab54)(auStack_124,auStack_140,iStack_12c,0x20);
            (*(code *)PTR_memset_006aab00)((int)auStack_124 + iVar12,0,0x10 - iVar10);
            goto LAB_0058ea18;
          }
        }
      }
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(list);
    pAVar8 = (ASN1_OCTET_STRING *)0x0;
  }
LAB_0058ead4:
  if (pXStack_104 == *(X509_NAME **)puVar4) {
    return pAVar8;
  }
  name = pXStack_104;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (name == (X509_NAME *)0x0) {
    return (ASN1_OCTET_STRING *)0x0;
  }
  iVar9 = 0;
  iVar7 = (*(code *)PTR_sk_num_006a7f2c)(puVar14);
  if (0 < iVar7) {
    do {
      iVar7 = (*(code *)PTR_sk_value_006a7f24)(puVar14,iVar9);
      pbVar15 = *(byte **)(iVar7 + 4);
      bVar1 = *pbVar15;
      if (bVar1 == 0) goto LAB_0058ed54;
      if ((bVar1 == 0x3a) || (pbVar6 = pbVar15, (bVar1 & 0xfd) == 0x2c)) {
        iVar10 = 0;
        pbVar16 = pbVar15;
        if ((pbVar15[1] != 0) && (pbVar16 = pbVar15 + 1, pbVar15[1] == 0x2b)) {
          pbVar16 = pbVar15 + 2;
          goto LAB_0058edd4;
        }
      }
      else {
        do {
          pbVar16 = pbVar6;
          bVar2 = pbVar16[1];
          if (bVar2 == 0) goto LAB_0058ed4c;
        } while ((bVar2 != 0x3a) && (pbVar6 = pbVar16 + 1, (bVar2 & 0xfd) != 0x2c));
        if (pbVar16[2] == 0) {
LAB_0058ed4c:
          if (bVar1 != 0x2b) {
LAB_0058ed54:
            iVar10 = 0;
            pbVar16 = pbVar15;
            goto LAB_0058ed58;
          }
          pbVar16 = pbVar15 + 1;
        }
        else {
          pbVar15 = pbVar16 + 2;
          if (pbVar16[2] != 0x2b) goto LAB_0058ed54;
          pbVar16 = pbVar16 + 3;
        }
LAB_0058edd4:
        iVar10 = -1;
      }
LAB_0058ed58:
      iVar7 = X509_NAME_add_entry_by_txt
                        (name,(char *)pbVar16,(int)puStack_b4,*(uchar **)(iVar7 + 8),-1,-1,iVar10);
      if (iVar7 == 0) {
        return (ASN1_OCTET_STRING *)0x0;
      }
      iVar9 = iVar9 + 1;
      iVar7 = (*(code *)PTR_sk_num_006a7f2c)(puVar14);
    } while (iVar9 < iVar7);
  }
  return (ASN1_OCTET_STRING *)0x1;
}

