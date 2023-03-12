
uint bitstr_cb(char *param_1,char **param_2,ASN1_BIT_STRING *param_3,char *param_4)

{
  char **ppcVar1;
  undefined *puVar2;
  char **n;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  uchar *puVar7;
  int iVar8;
  int iVar9;
  ASN1_BIT_STRING *pAVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  char *unaff_s1;
  char *pcVar13;
  ASN1_BIT_STRING *unaff_s2;
  char **unaff_s3;
  char **ppcVar14;
  int iStack_84;
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  undefined *puStack_70;
  char *pcStack_6c;
  ASN1_BIT_STRING *pAStack_68;
  char **ppcStack_64;
  char *local_20;
  char *local_1c;
  
  puStack_70 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(char **)PTR___stack_chk_guard_006a9ae8;
  ppcVar14 = param_2;
  pAVar10 = param_3;
  if (param_1 == (char *)0x0) {
LAB_00565cc8:
    n = ppcVar14;
    uVar3 = 0;
    param_1 = unaff_s1;
    param_3 = unaff_s2;
    param_2 = unaff_s3;
  }
  else {
    ppcVar14 = &local_20;
    pAVar10 = (ASN1_BIT_STRING *)&DAT_0000000a;
    n = (char **)(*(code *)PTR_strtoul_006a9a2c)();
    unaff_s2 = param_3;
    unaff_s3 = param_2;
    if (((local_20 != (char *)0x0) && (param_1 = param_1 + (int)param_2, *local_20 != '\0')) &&
       (unaff_s1 = param_1, local_20 != param_1)) goto LAB_00565cc8;
    if ((int)n < 0) {
      pAVar10 = (ASN1_BIT_STRING *)0xbb;
      param_4 = "asn1_gen.c";
      ppcVar14 = (char **)&DAT_000000b4;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb4,0xbb,"asn1_gen.c");
      unaff_s1 = param_1;
      goto LAB_00565cc8;
    }
    pAVar10 = (ASN1_BIT_STRING *)0x1;
    uVar3 = ASN1_BIT_STRING_set_bit(param_3,(int)n,1);
    if (uVar3 == 0) {
      pAVar10 = (ASN1_BIT_STRING *)&DAT_00000041;
      param_4 = "asn1_gen.c";
      n = (char **)&DAT_000000b4;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb4,0x41,"asn1_gen.c");
    }
    else {
      uVar3 = 1;
    }
  }
  if (local_1c == *(char **)puStack_70) {
    return uVar3;
  }
  pcVar6 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iStack_74 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar3 = 0xffffffff;
  pcStack_6c = param_1;
  pAStack_68 = param_3;
  ppcStack_64 = param_2;
  if (pcVar6 == (char *)0x0) goto LAB_00565ea0;
  if ((int)n < 1) {
    pcVar13 = (char *)0x0;
    iStack_84 = 0;
  }
  else {
    pcVar13 = pcVar6;
    if (*pcVar6 == ':') {
      ppcVar14 = (char **)0x0;
    }
    else {
      do {
        pcVar13 = pcVar13 + 1;
        if (pcVar13 == pcVar6 + (int)n) {
          pcVar13 = (char *)0x0;
          iStack_84 = 0;
          ppcVar14 = n;
          goto LAB_00565e20;
        }
        ppcVar14 = (char **)(pcVar13 + -(int)pcVar6);
      } while (*pcVar13 != ':');
    }
    pcVar13 = pcVar13 + 1;
    iStack_84 = (int)n - ((int)pcVar13 - (int)pcVar6);
    n = ppcVar14;
  }
  ppcVar14 = n;
  if (n == (char **)0xffffffff) {
    ppcVar14 = (char **)(*(code *)PTR_strlen_006a9a24)(pcVar6);
  }
LAB_00565e20:
  tntmp_13679 = tnst_13680;
  puVar12 = (undefined4 *)tnst_13680;
  if (ppcVar14 == (char **)&SUB_00000004) goto LAB_00565e58;
  do {
    do {
      tntmp_13679 = (undefined1 *)(puVar12 + 3);
      if (tntmp_13679 == tag2str_7244) goto LAB_00565ee0;
      ppcVar1 = (char **)(puVar12 + 4);
      puVar12 = (undefined4 *)tntmp_13679;
    } while (ppcVar14 != (char **)*ppcVar1);
LAB_00565e58:
    puVar12 = (undefined4 *)tntmp_13679;
    iVar4 = (*(code *)PTR_strncmp_006a9970)(*(undefined4 *)tntmp_13679,pcVar6,ppcVar14);
  } while (iVar4 != 0);
  puVar7 = (uchar *)puVar12[2];
  if (puVar7 == (uchar *)0xffffffff) {
LAB_00565ee0:
    param_4 = "asn1_gen.c";
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb1,0xc2,"asn1_gen.c",0x13e);
    (*(code *)PTR_ERR_add_error_data_006a813c)(2,&DAT_0066a464,pcVar6);
    uVar3 = 0xffffffff;
    goto LAB_00565ea0;
  }
  uVar3 = (uint)puVar7 & 0x10000;
  if (uVar3 == 0) {
    pAVar10->data = puVar7;
    pAVar10[1].length = (int)pcVar13;
    if ((pcVar13 == (char *)0x0) && (param_4 = "encrypt", pcVar6[(int)n] != '\0')) {
      uVar11 = 0xbd;
      param_4 = "asn1_gen.c";
      uVar5 = 0x149;
      goto LAB_00566204;
    }
    goto LAB_00565ea0;
  }
  switch(puVar7) {
  case (uchar *)0x10001:
    if (pAVar10->length != -1) {
      uVar11 = 0xb5;
      param_4 = "asn1_gen.c";
      uVar5 = 0x154;
      goto LAB_00566204;
    }
    param_4 = (char *)&pAVar10->type;
    iVar4 = parse_tagging(pcVar13,iStack_84,pAVar10,param_4);
    if (iVar4 == 0) goto LAB_005661a8;
  default:
    uVar3 = 1;
    goto LAB_00565ea0;
  case (uchar *)0x10002:
    param_4 = (char *)&iStack_78;
    iVar4 = parse_tagging(pcVar13,iStack_84,&iStack_7c,param_4);
    if (iVar4 != 0) {
      param_4 = "encrypt";
      if (pAVar10->length == -1) {
        iVar4 = pAVar10[0x1a].type;
        if (iVar4 != 0x14) {
          pAVar10[0x1a].type = iVar4 + 1;
          uVar3 = 1;
          *(int *)((int)pAVar10 + iVar4 * 0x14 + 0x14) = iStack_7c;
          *(undefined4 *)((int)pAVar10 + iVar4 * 0x14 + 0x20) = 0;
          *(int *)((int)pAVar10 + iVar4 * 0x14 + 0x18) = iStack_78;
          *(undefined4 *)((int)pAVar10 + iVar4 * 0x14 + 0x1c) = 1;
          goto LAB_00565ea0;
        }
        uVar11 = 0xae;
        uVar5 = 0x218;
      }
      else {
        uVar11 = 0xb3;
        uVar5 = 0x213;
      }
      param_4 = "asn1_gen.c";
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb0,uVar11,"asn1_gen.c",uVar5);
    }
LAB_005661a8:
    uVar3 = 0xffffffff;
    goto LAB_00565ea0;
  case (uchar *)0x10004:
    iVar8 = pAVar10[0x1a].type;
    iVar9 = pAVar10->length;
    if (iVar8 != 0x14) {
      pAVar10[0x1a].type = iVar8 + 1;
      if (iVar9 == -1) {
        iVar9 = 3;
      }
      else {
        iVar4 = pAVar10->type;
        pAVar10->length = -1;
        pAVar10->type = -1;
      }
      uVar3 = 1;
      *(int *)((int)pAVar10 + iVar8 * 0x14 + 0x18) = iVar4;
      *(int *)((int)pAVar10 + iVar8 * 0x14 + 0x14) = iVar9;
      *(undefined4 *)((int)pAVar10 + iVar8 * 0x14 + 0x1c) = 0;
      *(undefined4 *)((int)pAVar10 + iVar8 * 0x14 + 0x20) = 1;
      goto LAB_00565ea0;
    }
    break;
  case (uchar *)0x10005:
    iVar8 = pAVar10[0x1a].type;
    iVar9 = pAVar10->length;
    if (iVar8 != 0x14) {
      pAVar10[0x1a].type = iVar8 + 1;
      if (iVar9 == -1) {
        iVar9 = 4;
      }
      else {
        iVar4 = pAVar10->type;
        pAVar10->length = -1;
        pAVar10->type = -1;
      }
      uVar3 = 1;
      *(int *)((int)pAVar10 + iVar8 * 0x14 + 0x18) = iVar4;
      *(int *)((int)pAVar10 + iVar8 * 0x14 + 0x14) = iVar9;
      *(undefined4 *)((int)pAVar10 + iVar8 * 0x14 + 0x1c) = 0;
      *(undefined4 *)((int)pAVar10 + iVar8 * 0x14 + 0x20) = 0;
      goto LAB_00565ea0;
    }
    break;
  case (uchar *)0x10006:
    iVar8 = pAVar10[0x1a].type;
    iVar9 = pAVar10->length;
    if (iVar8 != 0x14) {
      pAVar10[0x1a].type = iVar8 + 1;
      if (iVar9 == -1) {
        iVar9 = 0x10;
      }
      else {
LAB_0056604c:
        iVar4 = pAVar10->type;
        pAVar10->length = -1;
        pAVar10->type = -1;
      }
LAB_00566058:
      uVar3 = 1;
      *(int *)((int)pAVar10 + iVar8 * 0x14 + 0x18) = iVar4;
      *(int *)((int)pAVar10 + iVar8 * 0x14 + 0x14) = iVar9;
      *(undefined4 *)((int)pAVar10 + iVar8 * 0x14 + 0x20) = 0;
      *(undefined4 *)((int)pAVar10 + iVar8 * 0x14 + 0x1c) = 1;
      goto LAB_00565ea0;
    }
    break;
  case (uchar *)0x10007:
    iVar8 = pAVar10[0x1a].type;
    iVar9 = pAVar10->length;
    if (iVar8 != 0x14) {
      pAVar10[0x1a].type = iVar8 + 1;
      if (iVar9 != -1) goto LAB_0056604c;
      iVar9 = 0x11;
      goto LAB_00566058;
    }
    break;
  case (uchar *)0x10008:
    param_4 = "encrypt";
    if (pcVar13 == (char *)0x0) goto LAB_00566334;
    iVar4 = (*(code *)PTR_strncmp_006a9970)(pcVar13,"ASCII",5);
    if (iVar4 == 0) {
      uVar3 = 1;
      pAVar10->flags = 1;
    }
    else {
      iVar4 = (*(code *)PTR_strncmp_006a9970)(pcVar13,&DAT_0066a474,4);
      if (iVar4 == 0) {
        uVar3 = 1;
        pAVar10->flags = 2;
      }
      else {
        iVar4 = (*(code *)PTR_strncmp_006a9970)(pcVar13,&DAT_0066a47c,3);
        if (iVar4 == 0) {
          uVar3 = 1;
          pAVar10->flags = 3;
        }
        else {
          iVar4 = (*(code *)PTR_strncmp_006a9970)(pcVar13,"BITLIST",7);
          if (iVar4 != 0) {
            uVar11 = 0xc3;
            param_4 = "asn1_gen.c";
            uVar5 = 0x185;
            goto LAB_00566204;
          }
          uVar3 = 1;
          pAVar10->flags = 4;
        }
      }
    }
    goto LAB_00565ea0;
  }
  param_4 = "asn1_gen.c";
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb0,0xae,"asn1_gen.c",0x218);
  uVar3 = 0xffffffff;
LAB_00565ea0:
  while (iStack_74 != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00566334:
    uVar11 = 0xa0;
    param_4 = (char *)((int)param_4 + -0x5bb8);
    uVar5 = 0x179;
LAB_00566204:
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb1,uVar11,param_4,uVar5);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

