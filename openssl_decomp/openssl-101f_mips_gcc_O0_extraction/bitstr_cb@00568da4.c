
uint bitstr_cb(char *param_1,char **param_2,ASN1_BIT_STRING *param_3)

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
  
  puStack_70 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(char **)PTR___stack_chk_guard_006aabf0;
  ppcVar14 = param_2;
  pAVar10 = param_3;
  if (param_1 == (char *)0x0) {
LAB_00568e14:
    n = ppcVar14;
    uVar3 = 0;
    param_1 = unaff_s1;
    param_3 = unaff_s2;
    param_2 = unaff_s3;
  }
  else {
    ppcVar14 = &local_20;
    pAVar10 = (ASN1_BIT_STRING *)&DAT_0000000a;
    n = (char **)(*(code *)PTR_strtoul_006aab38)();
    unaff_s2 = param_3;
    unaff_s3 = param_2;
    if (((local_20 != (char *)0x0) && (param_1 = param_1 + (int)param_2, *local_20 != '\0')) &&
       (unaff_s1 = param_1, local_20 != param_1)) goto LAB_00568e14;
    if ((int)n < 0) {
      pAVar10 = (ASN1_BIT_STRING *)0xbb;
      ppcVar14 = (char **)&DAT_000000b4;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb4,0xbb,"asn1_gen.c");
      unaff_s1 = param_1;
      goto LAB_00568e14;
    }
    pAVar10 = (ASN1_BIT_STRING *)0x1;
    uVar3 = ASN1_BIT_STRING_set_bit(param_3,(int)n,1);
    if (uVar3 == 0) {
      pAVar10 = (ASN1_BIT_STRING *)&DAT_00000041;
      n = (char **)&DAT_000000b4;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb4,0x41,"asn1_gen.c");
    }
    else {
      uVar3 = 1;
    }
  }
  if (local_1c == *(char **)puStack_70) {
    return uVar3;
  }
  pcVar6 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iStack_74 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_6c = param_1;
  pAStack_68 = param_3;
  ppcStack_64 = param_2;
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
          goto LAB_00568f64;
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
    ppcVar14 = (char **)(*(code *)PTR_strlen_006aab30)(pcVar6);
  }
LAB_00568f64:
  tntmp_13652 = tnst_13653;
  puVar12 = (undefined4 *)tnst_13653;
  if (ppcVar14 == (char **)&SUB_00000004) goto LAB_00568f9c;
  do {
    do {
      tntmp_13652 = (undefined1 *)(puVar12 + 3);
      if (tntmp_13652 == tag2str_7235) goto LAB_00569024;
      ppcVar1 = (char **)(puVar12 + 4);
      puVar12 = (undefined4 *)tntmp_13652;
    } while (ppcVar14 != (char **)*ppcVar1);
LAB_00568f9c:
    puVar12 = (undefined4 *)tntmp_13652;
    iVar4 = (*(code *)PTR_strncmp_006aaa7c)(*(undefined4 *)tntmp_13652,pcVar6,ppcVar14);
  } while (iVar4 != 0);
  puVar7 = (uchar *)puVar12[2];
  if (puVar7 == (uchar *)0xffffffff) {
LAB_00569024:
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb1,0xc2,"asn1_gen.c",0x12f);
    (*(code *)PTR_ERR_add_error_data_006a9264)(2,&DAT_0066ae7c,pcVar6);
    uVar3 = 0xffffffff;
    goto LAB_00568fe4;
  }
  uVar3 = (uint)puVar7 & 0x10000;
  if (uVar3 == 0) {
    pAVar10->data = puVar7;
    pAVar10[1].length = (int)pcVar13;
    if ((pcVar13 == (char *)0x0) && (pcVar6[(int)n] != '\0')) {
      uVar11 = 0xbd;
      uVar5 = 0x13c;
      goto LAB_00569340;
    }
    goto LAB_00568fe4;
  }
  switch(puVar7) {
  case (uchar *)0x10001:
    if (pAVar10->length != -1) {
      uVar11 = 0xb5;
      uVar5 = 0x149;
      goto LAB_00569340;
    }
    iVar4 = parse_tagging(pcVar13,iStack_84,pAVar10,&pAVar10->type);
    if (iVar4 == 0) goto LAB_005692e4;
  default:
    uVar3 = 1;
    goto LAB_00568fe4;
  case (uchar *)0x10002:
    iVar4 = parse_tagging(pcVar13,iStack_84,&iStack_7c,&iStack_78);
    if (iVar4 != 0) {
      if (pAVar10->length == -1) {
        iVar4 = pAVar10[0x1a].type;
        if (iVar4 != 0x14) {
          pAVar10[0x1a].type = iVar4 + 1;
          uVar3 = 1;
          *(int *)((int)pAVar10 + iVar4 * 0x14 + 0x14) = iStack_7c;
          *(undefined4 *)((int)pAVar10 + iVar4 * 0x14 + 0x20) = 0;
          *(int *)((int)pAVar10 + iVar4 * 0x14 + 0x18) = iStack_78;
          *(undefined4 *)((int)pAVar10 + iVar4 * 0x14 + 0x1c) = 1;
          goto LAB_00568fe4;
        }
        uVar11 = 0xae;
        uVar5 = 0x20c;
      }
      else {
        uVar11 = 0xb3;
        uVar5 = 0x206;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb0,uVar11,"asn1_gen.c",uVar5);
    }
LAB_005692e4:
    uVar3 = 0xffffffff;
    goto LAB_00568fe4;
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
      goto LAB_00568fe4;
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
      goto LAB_00568fe4;
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
LAB_00569188:
        iVar4 = pAVar10->type;
        pAVar10->length = -1;
        pAVar10->type = -1;
      }
LAB_00569194:
      uVar3 = 1;
      *(int *)((int)pAVar10 + iVar8 * 0x14 + 0x18) = iVar4;
      *(int *)((int)pAVar10 + iVar8 * 0x14 + 0x14) = iVar9;
      *(undefined4 *)((int)pAVar10 + iVar8 * 0x14 + 0x20) = 0;
      *(undefined4 *)((int)pAVar10 + iVar8 * 0x14 + 0x1c) = 1;
      goto LAB_00568fe4;
    }
    break;
  case (uchar *)0x10007:
    iVar8 = pAVar10[0x1a].type;
    iVar9 = pAVar10->length;
    if (iVar8 != 0x14) {
      pAVar10[0x1a].type = iVar8 + 1;
      if (iVar9 != -1) goto LAB_00569188;
      iVar9 = 0x11;
      goto LAB_00569194;
    }
    break;
  case (uchar *)0x10008:
    iVar4 = (*(code *)PTR_strncmp_006aaa7c)(pcVar13,"ASCII",5);
    if (iVar4 == 0) {
      uVar3 = 1;
      pAVar10->flags = 1;
    }
    else {
      iVar4 = (*(code *)PTR_strncmp_006aaa7c)(pcVar13,&DAT_0066ae8c,4);
      if (iVar4 == 0) {
        uVar3 = 1;
        pAVar10->flags = 2;
      }
      else {
        iVar4 = (*(code *)PTR_strncmp_006aaa7c)(pcVar13,&DAT_0066ae94,3);
        if (iVar4 == 0) {
          uVar3 = 1;
          pAVar10->flags = 3;
        }
        else {
          iVar4 = (*(code *)PTR_strncmp_006aaa7c)(pcVar13,"BITLIST",3);
          if (iVar4 != 0) goto LAB_00569458;
          uVar3 = 1;
          pAVar10->flags = 4;
        }
      }
    }
    goto LAB_00568fe4;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb0,0xae,"asn1_gen.c",0x20c);
  uVar3 = 0xffffffff;
LAB_00568fe4:
  while (iStack_74 != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00569458:
    uVar11 = 0xc3;
    uVar5 = 0x177;
LAB_00569340:
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb1,uVar11,"asn1_gen.c",uVar5);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

