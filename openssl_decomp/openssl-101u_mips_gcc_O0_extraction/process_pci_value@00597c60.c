
PROXY_CERT_INFO_EXTENSION *
process_pci_value(CONF_VALUE *param_1,int *param_2,char *param_3,stack_st_void *param_4)

{
  undefined *puVar1;
  int *piVar2;
  X509_CINF *pXVar3;
  stack_st_CONF_VALUE *psVar4;
  int iVar5;
  X509 **ppXVar6;
  uint uVar7;
  PROXY_CERT_INFO_EXTENSION *pPVar8;
  PROXY_POLICY *pPVar9;
  stack_st_CONF_VALUE *section;
  int iVar10;
  uchar *puVar11;
  uchar **ppuVar12;
  char *pcVar13;
  X509 *pXVar14;
  undefined4 uVar15;
  X509 *line;
  undefined4 uVar16;
  char *pcVar17;
  int iVar18;
  char *pcVar19;
  ulong unaff_s7;
  ASIdentifierChoice **ppAVar20;
  ASIdentifierChoice *pAVar21;
  undefined *unaff_s8;
  ASN1_OBJECT *pAStack_898;
  undefined auStack_894 [4];
  ASN1_OCTET_STRING *pAStack_890;
  ASN1_BIT_STRING *pAStack_88c;
  PROXY_CERT_INFO_EXTENSION *pPStack_888;
  CONF_VALUE *pCStack_884;
  char *pcStack_880;
  stack_st_void *psStack_87c;
  uchar *puStack_878;
  int *piStack_874;
  X509 *pXStack_870;
  ulong uStack_86c;
  undefined *puStack_868;
  code *pcStack_864;
  stack_st_DIST_POINT *local_850;
  char *local_84c;
  NAME_CONSTRAINTS *local_848;
  ASIdentifiers_st *local_840;
  char *local_838;
  int local_834;
  X509 *local_830;
  undefined auStack_82c [2048];
  int local_2c;
  
  pcStack_880 = PTR___stack_chk_guard_006a9ae8;
  local_840 = (ASIdentifiers_st *)&_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_878 = (uchar *)param_1->name;
  line = (X509 *)param_3;
  pPStack_888 = (PROXY_CERT_INFO_EXTENSION *)(*(code *)PTR_strcmp_006a9b18)(puStack_878,"language");
  if (pPStack_888 == (PROXY_CERT_INFO_EXTENSION *)0x0) {
    if (*param_2 == 0) {
      pcVar13 = (char *)0x0;
      iVar5 = (*(code *)local_840[-0xfbc].asnum)(param_1->value);
      *param_2 = iVar5;
      if (iVar5 != 0) goto LAB_00597ee8;
      ppAVar20 = local_840[-0xdd6].rdi;
      uVar15 = 0x6e;
      local_850 = (stack_st_DIST_POINT *)0x5b;
    }
    else {
      ppAVar20 = local_840[-0xdd6].rdi;
      uVar15 = 0x9b;
      local_850 = (stack_st_DIST_POINT *)&DAT_00000055;
    }
LAB_00597cf4:
    (*(code *)ppAVar20)(0x22,0x96,uVar15,"v3_pci.c");
    local_848 = (NAME_CONSTRAINTS *)param_1->value;
    local_850 = (stack_st_DIST_POINT *)param_1->name;
    pcVar13 = "section:";
    line = (X509 *)param_1->section;
    local_84c = ",value:";
    (*(code *)local_840[-0xd95].rdi)(6,"section:",line,",name:");
  }
  else {
    pPStack_888 = (PROXY_CERT_INFO_EXTENSION *)
                  (*(code *)local_840[-0xa59].asnum)(puStack_878,"pathlen");
    if (pPStack_888 == (PROXY_CERT_INFO_EXTENSION *)0x0) {
      if (*(X509_CINF **)param_3 == (X509_CINF *)0x0) {
        pcVar13 = param_3;
        pPStack_888 = (PROXY_CERT_INFO_EXTENSION *)
                      X509V3_get_value_int(param_1,(ASN1_INTEGER **)param_3);
        if (pPStack_888 != (PROXY_CERT_INFO_EXTENSION *)0x0) goto LAB_00597ee8;
        ppAVar20 = local_840[-0xdd6].rdi;
        uVar15 = 0x9c;
        local_850 = (stack_st_DIST_POINT *)&DAT_00000068;
      }
      else {
        ppAVar20 = local_840[-0xdd6].rdi;
        uVar15 = 0x9d;
        local_850 = (stack_st_DIST_POINT *)0x62;
      }
      goto LAB_00597cf4;
    }
    pcVar13 = "policy";
    pPStack_888 = (PROXY_CERT_INFO_EXTENSION *)(*(code *)local_840[-0xa59].asnum)(puStack_878);
    if (pPStack_888 == (PROXY_CERT_INFO_EXTENSION *)0x0) {
      param_2 = (int *)(param_4->stack).num;
      local_834 = 0;
      if (param_2 == (int *)0x0) {
        param_2 = (int *)(*(code *)local_840[-0xcef].asnum)();
        (param_4->stack).num = (int)param_2;
        local_834 = 1;
        if (param_2 == (int *)0x0) {
          ppAVar20 = local_840[-0xdd6].rdi;
          uVar15 = 0x41;
          local_850 = (stack_st_DIST_POINT *)0x72;
          goto LAB_00597cf4;
        }
      }
      puStack_878 = (uchar *)param_1->value;
      iVar5 = (*(code *)local_840[-0xa8e].asnum)(puStack_878,&DAT_0066ed60,4);
      if (iVar5 == 0) {
        puStack_878 = string_to_hex((char *)(puStack_878 + 4),(long *)&local_830);
        if (puStack_878 == (uchar *)0x0) {
          ppAVar20 = local_840[-0xdd6].rdi;
          uVar15 = 0x71;
          pcVar13 = "v3_pci.c";
          local_850 = (stack_st_DIST_POINT *)0x7e;
        }
        else {
          piVar2 = (int *)(param_4->stack).num;
          param_2 = (int *)0x670000;
          iVar5 = (*(code *)local_840[-0xe51].asnum)
                            (piVar2[2],local_830->sha1_hash + *piVar2 + -0x57,"v3_pci.c",0x84);
          if (iVar5 != 0) {
            ppAVar20 = local_840[-0xa5f].rdi;
            pPStack_888 = (PROXY_CERT_INFO_EXTENSION *)0x1;
            *(int *)((param_4->stack).num + 8) = iVar5;
            piVar2 = (int *)(param_4->stack).num;
            (*(code *)ppAVar20)(piVar2[2] + *piVar2,puStack_878,local_830);
            pcVar13 = (char *)(param_4->stack).num;
            pXVar3 = *(X509_CINF **)pcVar13;
            pAVar21 = local_840[-0xfeb].asnum;
            *(X509_CINF **)pcVar13 = (X509_CINF *)(local_830->sha1_hash + (int)&pXVar3[-2].validity)
            ;
            ((X509 *)((*(X509 **)((int)pcVar13 + 8))->sha1_hash + -0x58))->sha1_hash
            [(int)(&((X509_CINF *)(local_830->sha1_hash + (int)&pXVar3[-2].validity))->version +
                  -0x16)] = '\0';
            line = local_830;
            (*(code *)pAVar21)(puStack_878);
            goto LAB_00597d48;
          }
          (*(code *)local_840[-0xfeb].asnum)(puStack_878);
          pcVar13 = "v3_pci.c";
          uVar15 = 0x41;
          *(undefined4 *)((param_4->stack).num + 8) = 0;
          ppAVar20 = local_840[-0xdd6].rdi;
          *(undefined4 *)(param_4->stack).num = 0;
          local_850 = (stack_st_DIST_POINT *)0x93;
        }
      }
      else {
        iVar5 = (*(code *)local_840[-0xa8e].asnum)(puStack_878,"file:",5);
        if (iVar5 == 0) {
          puStack_878 = (uchar *)(*(code *)local_840[-0xfe7].rdi)(puStack_878 + 5,"r");
          if (puStack_878 == (uchar *)0x0) {
            ppAVar20 = local_840[-0xdd6].rdi;
            uVar15 = 0x20;
            pcVar13 = "v3_pci.c";
            local_850 = (stack_st_DIST_POINT *)0x9d;
          }
          else {
            param_2 = (int *)0x0;
            unaff_s8 = auStack_82c;
            param_3 = "v3_pci.c";
            do {
              line = (X509 *)0x800;
              unaff_s7 = (*(code *)local_840[-0xf24].asnum)(puStack_878,unaff_s8);
              while (0 < (int)unaff_s7) {
                piVar2 = (int *)(param_4->stack).num;
                local_838 = "encrypt";
                param_2 = (int *)(*(code *)local_840[-0xe51].asnum)
                                           (piVar2[2],unaff_s7 + *piVar2 + 1,"v3_pci.c",0xa7);
                if (param_2 == (int *)0x0) {
                  (*(code *)local_840[-0xfee].rdi)(puStack_878);
                  goto LAB_005981c4;
                }
                ppAVar20 = local_840[-0xa5f].rdi;
                *(int **)((param_4->stack).num + 8) = param_2;
                piVar2 = (int *)(param_4->stack).num;
                (*(code *)ppAVar20)(piVar2[2] + *piVar2,unaff_s8,unaff_s7);
                line = (X509 *)0x800;
                piVar2 = (int *)(param_4->stack).num;
                iVar5 = *piVar2;
                pAVar21 = local_840[-0xf24].asnum;
                *piVar2 = unaff_s7 + iVar5;
                *(undefined *)(piVar2[2] + unaff_s7 + iVar5) = 0;
                unaff_s7 = (*(code *)pAVar21)(puStack_878,unaff_s8);
              }
              if (unaff_s7 != 0) {
                (*(code *)local_840[-0xfee].rdi)(puStack_878);
                uVar15 = 0x20;
                pcVar13 = "v3_pci.c";
                local_850 = (stack_st_DIST_POINT *)&DAT_000000b4;
                ppAVar20 = local_840[-0xdd6].rdi;
                goto LAB_00597f78;
              }
              pcVar13 = &DAT_00000008;
              iVar5 = (*(code *)local_840[-0xeaf].asnum)(puStack_878);
            } while (iVar5 != 0);
            (*(code *)local_840[-0xfee].rdi)(puStack_878);
            if (param_2 != (int *)0x0) goto LAB_00597ee8;
            local_838 = "encrypt";
LAB_005981c4:
            pcVar13 = local_838 + -0x12b4;
            ppAVar20 = local_840[-0xdd6].rdi;
            uVar15 = 0x41;
            local_850 = (stack_st_DIST_POINT *)&DAT_000000d4;
          }
        }
        else {
          iVar5 = (*(code *)local_840[-0xa8e].asnum)(puStack_878,"text:",5);
          if (iVar5 == 0) {
            puVar11 = puStack_878 + 5;
            puStack_878 = "encrypt";
            local_830 = (X509 *)(*(code *)local_840[-0xa78].rdi)(puVar11);
            iVar5 = (*(code *)local_840[-0xe51].asnum)
                              (param_2[2],local_830->sha1_hash + *param_2 + -0x57,"v3_pci.c",0xbb);
            if (iVar5 != 0) {
              pcVar13 = param_1->value;
              ppAVar20 = local_840[-0xa5f].rdi;
              *(int *)((param_4->stack).num + 8) = iVar5;
              piVar2 = (int *)(param_4->stack).num;
              line = local_830;
              (*(code *)ppAVar20)(piVar2[2] + *piVar2,pcVar13 + 5);
              ppuVar12 = (uchar **)(param_4->stack).num;
              puVar11 = *ppuVar12;
              *ppuVar12 = local_830->sha1_hash + (int)(puVar11 + -0x58);
              (local_830->sha1_hash + (int)(puVar11 + -0x58))[(int)ppuVar12[2]] = '\0';
              pcVar13 = (char *)local_830;
              goto LAB_00597ee8;
            }
            pcVar13 = "v3_pci.c";
            ppAVar20 = local_840[-0xdd6].rdi;
            uVar15 = 0x41;
            *(undefined4 *)((param_4->stack).num + 8) = 0;
            *(undefined4 *)(param_4->stack).num = 0;
            local_850 = (stack_st_DIST_POINT *)0xc9;
          }
          else {
            ppAVar20 = local_840[-0xdd6].rdi;
            uVar15 = 0x98;
            pcVar13 = "v3_pci.c";
            local_850 = (stack_st_DIST_POINT *)0xcf;
          }
        }
      }
LAB_00597f78:
      (*(code *)ppAVar20)(0x22,0x96,uVar15,pcVar13);
      local_848 = (NAME_CONSTRAINTS *)param_1->value;
      local_850 = (stack_st_DIST_POINT *)param_1->name;
      pcVar13 = "section:";
      line = (X509 *)param_1->section;
      local_84c = ",value:";
      (*(code *)local_840[-0xd95].rdi)(6,"section:",line,",name:");
      if (local_834 != 0) {
        (*(code *)local_840[-0xc1d].rdi)((param_4->stack).num);
        (param_4->stack).num = 0;
      }
    }
    else {
LAB_00597ee8:
      pPStack_888 = (PROXY_CERT_INFO_EXTENSION *)0x1;
    }
  }
LAB_00597d48:
  if (local_2c == *(int *)pcStack_880) {
    return pPStack_888;
  }
  pcStack_864 = r2i_pci;
  (*(code *)local_840[-0xa66].asnum)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pcVar19 = auStack_894 + 4;
  iVar18 = 0;
  pAStack_898 = (ASN1_OBJECT *)0x0;
  auStack_894 = (undefined  [4])0x0;
  pAStack_890 = (ASN1_OCTET_STRING *)0x0;
  pAStack_88c = *(ASN1_BIT_STRING **)PTR___stack_chk_guard_006a9ae8;
  pCStack_884 = param_1;
  psStack_87c = param_4;
  piStack_874 = param_2;
  pXStack_870 = (X509 *)param_3;
  uStack_86c = unaff_s7;
  puStack_868 = unaff_s8;
  psVar4 = X509V3_parse_list((char *)line);
  iVar5 = (*(code *)PTR_sk_num_006a6e2c)(psVar4);
  if (0 < iVar5) {
    do {
      ppXVar6 = (X509 **)(*(code *)PTR_sk_value_006a6e24)(psVar4,iVar18);
      pXVar14 = ppXVar6[1];
      if (pXVar14 == (X509 *)0x0) {
LAB_005985d4:
        uVar16 = 0x99;
        uVar15 = 0xf1;
LAB_005985e8:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x9b,uVar16,"v3_pci.c",uVar15);
        line = *ppXVar6;
        pcVar17 = ",name:";
        (*(code *)PTR_ERR_add_error_data_006a813c)
                  (6,"section:",line,",name:",ppXVar6[1],",value:",ppXVar6[2]);
        goto LAB_0059850c;
      }
      if (*(char *)&pXVar14->cert_info == '@') {
        section = X509V3_get_section((X509V3_CTX *)pcVar13,(char *)((int)&pXVar14->cert_info + 1));
        if (section == (stack_st_CONF_VALUE *)0x0) {
          uVar16 = 0x87;
          uVar15 = 0xfb;
          goto LAB_005985e8;
        }
        iVar5 = 0;
        while (iVar10 = (*(code *)PTR_sk_num_006a6e2c)(section), iVar5 < iVar10) {
          uVar15 = (*(code *)PTR_sk_value_006a6e24)(section,iVar5);
          line = (X509 *)auStack_894;
          pcVar17 = pcVar19;
          iVar10 = process_pci_value(uVar15,&pAStack_898,(X509 *)auStack_894,pcVar19);
          iVar5 = iVar5 + 1;
          if (iVar10 == 0) {
            X509V3_section_free((X509V3_CTX *)pcVar13,section);
            goto LAB_0059850c;
          }
        }
        X509V3_section_free((X509V3_CTX *)pcVar13,section);
      }
      else {
        if (ppXVar6[2] == (X509 *)0x0) goto LAB_005985d4;
        line = (X509 *)auStack_894;
        iVar5 = process_pci_value(ppXVar6,&pAStack_898,(X509 *)auStack_894,pcVar19);
        if (iVar5 == 0) {
          line = *ppXVar6;
          pcVar17 = ",name:";
          (*(code *)PTR_ERR_add_error_data_006a813c)
                    (6,"section:",line,",name:",ppXVar6[1],",value:",ppXVar6[2]);
          goto LAB_0059850c;
        }
      }
      iVar18 = iVar18 + 1;
      iVar5 = (*(code *)PTR_sk_num_006a6e2c)(psVar4);
    } while (iVar18 < iVar5);
  }
  pcVar17 = "encrypt";
  if (pAStack_898 == (ASN1_OBJECT *)0x0) {
    line = (X509 *)0x9a;
    uVar15 = 0x112;
  }
  else {
    uVar7 = (*(code *)PTR_OBJ_obj2nid_006a712c)();
    if (((uVar7 & 0xfffffffd) == 0x299) &&
       (pcVar17 = "encrypt", pAStack_890 != (ASN1_OCTET_STRING *)0x0)) {
      line = (X509 *)0x9f;
      uVar15 = 0x118;
    }
    else {
      pPVar8 = PROXY_CERT_INFO_EXTENSION_new();
      if (pPVar8 != (PROXY_CERT_INFO_EXTENSION *)0x0) {
        pPVar9 = pPVar8->proxyPolicy;
        pPVar9->policyLanguage = pAStack_898;
        pPVar9->policy = pAStack_890;
        pAStack_898 = (ASN1_OBJECT *)0x0;
        pAStack_890 = (ASN1_OCTET_STRING *)0x0;
        pPVar8->pcPathLengthConstraint = (ASN1_INTEGER *)auStack_894;
        auStack_894 = (undefined  [4])0x0;
        goto LAB_00598560;
      }
      line = (X509 *)&DAT_00000041;
      uVar15 = 0x11e;
    }
  }
  pcVar17 = "v3_pci.c";
  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x9b,line,"v3_pci.c",uVar15);
LAB_0059850c:
  if (pAStack_898 != (ASN1_OBJECT *)0x0) {
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)();
    pAStack_898 = (ASN1_OBJECT *)0x0;
  }
  if (auStack_894 != (undefined  [4])0x0) {
    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)();
    auStack_894 = (undefined  [4])0x0;
  }
  if (pAStack_890 == (ASN1_OCTET_STRING *)0x0) {
    pPVar8 = (PROXY_CERT_INFO_EXTENSION *)0x0;
  }
  else {
    pPVar8 = (PROXY_CERT_INFO_EXTENSION *)0x0;
    (*(code *)PTR_ASN1_OCTET_STRING_free_006a8cfc)();
    pAStack_890 = (ASN1_OCTET_STRING *)0x0;
  }
LAB_00598560:
  piVar2 = (int *)PTR_X509V3_conf_free_006a7b4c;
  (*(code *)PTR_sk_pop_free_006a7058)(psVar4);
  if (pAStack_88c == *(ASN1_BIT_STRING **)puVar1) {
    return pPVar8;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  (*(code *)PTR_BIO_printf_006a6e38)(line,"%*sPath Length Constraint: ",pcVar17,"");
  if (*piVar2 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(line,"infinite");
  }
  else {
    (*(code *)PTR_i2a_ASN1_INTEGER_006a75f0)(line);
  }
  (*(code *)PTR_BIO_puts_006a6f58)(line,"\n");
  (*(code *)PTR_BIO_printf_006a6e38)(line,"%*sPolicy Language: ",pcVar17,"");
  (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)(line,*(undefined4 *)piVar2[1]);
  (*(code *)PTR_BIO_puts_006a6f58)(line,"\n");
  if ((*(int *)(piVar2[1] + 4) != 0) && (iVar5 = *(int *)(*(int *)(piVar2[1] + 4) + 8), iVar5 != 0))
  {
    (*(code *)PTR_BIO_printf_006a6e38)(line,"%*sPolicy Text: %s\n",pcVar17,"",iVar5);
  }
  return (PROXY_CERT_INFO_EXTENSION *)0x1;
}

