
ASN1_OCTET_STRING * a2i_IPADDRESS_NC(char *ipasc)

{
  byte bVar1;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  byte *pbVar5;
  int iVar6;
  char *list;
  int iVar7;
  int iVar8;
  ASN1_OCTET_STRING *pAVar9;
  int iVar10;
  X509_NAME *name;
  uint *ipasc_00;
  uint *puVar11;
  byte *pbVar12;
  byte *pbVar13;
  uint *in_a2;
  uint local_70;
  uint local_6c;
  uint *local_68;
  uint *local_64;
  uint local_60 [4];
  int local_50;
  int local_4c;
  int local_48;
  uint local_44 [4];
  undefined auStack_34 [16];
  X509_NAME *local_24;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  ipasc_00 = (uint *)0x2f;
  local_24 = *(X509_NAME **)PTR___stack_chk_guard_006a9ae8;
  iVar6 = (*(code *)PTR_strchr_006a9a28)(ipasc,0x2f);
  if ((iVar6 == 0) ||
     (list = (char *)(*(code *)PTR_BUF_strdup_006a6fdc)(ipasc), puVar3 = PTR_strchr_006a9a28,
     list == (char *)0x0)) {
LAB_0058bd14:
    puVar11 = ipasc_00;
    pAVar9 = (ASN1_OCTET_STRING *)0x0;
  }
  else {
    list[iVar6 - (int)ipasc] = '\0';
    iVar7 = (*(code *)puVar3)(list,0x3a);
    if (iVar7 == 0) {
      in_a2 = &local_70;
      puVar11 = (uint *)0x66ec80;
      iVar7 = (*(code *)PTR___isoc99_sscanf_006a9a04)
                        (list,"%d.%d.%d.%d",in_a2,&local_6c,&local_68,&local_64);
      if ((((iVar7 == 4) && (local_70 < 0x100)) && (puVar11 = local_68, local_6c < 0x100)) &&
         ((in_a2 = local_64, local_68 < (uint *)0x100 && (iVar10 = 4, local_64 < (uint *)0x100)))) {
        local_44[0] = (uint)local_64 & 0xff |
                      (uint)CONCAT21(CONCAT11((char)local_70,(char)local_6c),(char)local_68) << 8;
LAB_0058bce0:
        puVar11 = local_44;
        ipasc_00 = (uint *)(list + (iVar6 - (int)ipasc) + 1);
        iVar6 = a2i_ipadd((uchar *)((int)puVar11 + iVar10),(char *)ipasc_00);
        (*(code *)PTR_CRYPTO_free_006a6e88)(list);
        in_a2 = local_64;
        if (((iVar6 != 0) && (iVar6 == iVar7)) &&
           (pAVar9 = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_OCTET_STRING_new_006a8668)(),
           in_a2 = local_64, pAVar9 != (ASN1_OCTET_STRING *)0x0)) {
          in_a2 = (uint *)(iVar7 << 1);
          iVar6 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a866c)(pAVar9,puVar11);
          if (iVar6 == 0) {
            (*(code *)PTR_ASN1_OCTET_STRING_free_006a8cfc)(pAVar9);
            pAVar9 = (ASN1_OCTET_STRING *)0x0;
          }
          goto LAB_0058bd7c;
        }
        goto LAB_0058bd14;
      }
    }
    else {
      local_50 = 0;
      local_48 = 0;
      local_64 = (uint *)0x0;
      local_4c = -1;
      puVar11 = (uint *)&DAT_0000003a;
      iVar8 = CONF_parse_list(list,0x3a,0,ipv6_cb,local_60);
      iVar10 = local_4c;
      iVar7 = local_50;
      in_a2 = local_64;
      if (iVar8 != 0) {
        if (local_4c == -1) {
          if (local_50 == 0x10) {
LAB_0058bdc4:
            local_44[0] = local_60[0];
LAB_0058bcdc:
            iVar10 = 0x10;
            iVar7 = 0x10;
            goto LAB_0058bce0;
          }
        }
        else if ((local_50 != 0x10) && (local_48 < 4)) {
          if (local_48 == 3) {
            if (local_50 < 1) {
              if (local_4c < 0) goto LAB_0058bdc4;
LAB_0058be80:
              (*(code *)PTR___memcpy_chk_006a9a48)(local_44,local_60,local_4c,0x20);
              local_64 = (uint *)(0x10 - iVar7);
              (*(code *)PTR_memset_006a99f4)((int)local_44 + iVar10,0);
              if (iVar10 == iVar7) goto LAB_0058bcdc;
LAB_0058bcc0:
              local_64 = (uint *)(iVar7 - iVar10);
              (*(code *)PTR_memcpy_006a9aec)
                        (&DAT_ffffffcc + (int)(&stack0x00000000 + (iVar10 - iVar7)),
                         (int)local_60 + iVar10);
              goto LAB_0058bcdc;
            }
          }
          else if (local_48 == 2) {
            if (local_4c == 0) goto LAB_0058be80;
            if (local_4c == local_50) {
              if (local_4c < 0) goto LAB_0058bdc4;
              (*(code *)PTR___memcpy_chk_006a9a48)(local_44,local_60,local_4c,0x20);
              local_64 = (uint *)(0x10 - iVar10);
              (*(code *)PTR_memset_006a99f4)((int)local_44 + iVar10,0);
              goto LAB_0058bcdc;
            }
          }
          else if ((local_4c != 0) && (local_4c != local_50)) {
            if (local_4c < 0) goto LAB_0058bdc4;
            (*(code *)PTR___memcpy_chk_006a9a48)(local_44,local_60,local_4c,0x20);
            (*(code *)PTR_memset_006a99f4)((int)local_44 + iVar10,0,0x10 - iVar7);
            goto LAB_0058bcc0;
          }
        }
      }
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(list);
    pAVar9 = (ASN1_OCTET_STRING *)0x0;
  }
LAB_0058bd7c:
  if (local_24 == *(X509_NAME **)puVar4) {
    return pAVar9;
  }
  name = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (name == (X509_NAME *)0x0) {
    return (ASN1_OCTET_STRING *)0x0;
  }
  iVar7 = 0;
  iVar6 = (*(code *)PTR_sk_num_006a6e2c)(puVar11);
  if (0 < iVar6) {
    do {
      iVar6 = (*(code *)PTR_sk_value_006a6e24)(puVar11,iVar7);
      pbVar12 = *(byte **)(iVar6 + 4);
      bVar1 = *pbVar12;
      if (bVar1 == 0) goto LAB_0058bffc;
      if ((bVar1 == 0x3a) || (pbVar5 = pbVar12, (bVar1 & 0xfd) == 0x2c)) {
        iVar10 = 0;
        pbVar13 = pbVar12;
        if ((pbVar12[1] != 0) && (pbVar13 = pbVar12 + 1, pbVar12[1] == 0x2b)) {
          pbVar13 = pbVar12 + 2;
          goto LAB_0058c07c;
        }
      }
      else {
        do {
          pbVar13 = pbVar5;
          bVar2 = pbVar13[1];
          if (bVar2 == 0) goto LAB_0058bff4;
        } while ((bVar2 != 0x3a) && (pbVar5 = pbVar13 + 1, (bVar2 & 0xfd) != 0x2c));
        if (pbVar13[2] == 0) {
LAB_0058bff4:
          if (bVar1 != 0x2b) {
LAB_0058bffc:
            iVar10 = 0;
            pbVar13 = pbVar12;
            goto LAB_0058c000;
          }
          pbVar13 = pbVar12 + 1;
        }
        else {
          pbVar12 = pbVar13 + 2;
          if (pbVar13[2] != 0x2b) goto LAB_0058bffc;
          pbVar13 = pbVar13 + 3;
        }
LAB_0058c07c:
        iVar10 = -1;
      }
LAB_0058c000:
      iVar6 = X509_NAME_add_entry_by_txt
                        (name,(char *)pbVar13,(int)in_a2,*(uchar **)(iVar6 + 8),-1,-1,iVar10);
      if (iVar6 == 0) {
        return (ASN1_OCTET_STRING *)0x0;
      }
      iVar7 = iVar7 + 1;
      iVar6 = (*(code *)PTR_sk_num_006a6e2c)(puVar11);
    } while (iVar7 < iVar6);
  }
  return (ASN1_OCTET_STRING *)0x1;
}

