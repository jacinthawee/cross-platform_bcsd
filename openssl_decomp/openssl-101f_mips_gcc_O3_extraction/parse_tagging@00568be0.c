
uint parse_tagging(ASN1_BIT_STRING *param_1,ASN1_BIT_STRING *param_2,ASN1_BIT_STRING *param_3,
                  undefined4 *param_4)

{
  ASN1_BIT_STRING **ppAVar1;
  char cVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  ASN1_BIT_STRING *n;
  undefined4 uVar6;
  char *pcVar7;
  uchar *puVar8;
  int iVar9;
  int iVar10;
  ASN1_BIT_STRING *pAVar11;
  undefined4 uVar12;
  ASN1_BIT_STRING *unaff_s0;
  undefined4 *puVar13;
  char *pcVar14;
  ASN1_BIT_STRING *unaff_s2;
  ASN1_BIT_STRING *pAVar15;
  ASN1_BIT_STRING *unaff_s3;
  ASN1_BIT_STRING *pAVar16;
  undefined4 *unaff_s4;
  ASN1_BIT_STRING *pAVar17;
  code *pcVar18;
  int iStack_cc;
  int iStack_c4;
  int iStack_c0;
  int iStack_bc;
  undefined *puStack_b8;
  uchar *puStack_b4;
  ASN1_BIT_STRING *pAStack_b0;
  char *pcStack_ac;
  undefined4 *puStack_a8;
  ASN1_BIT_STRING AStack_68;
  undefined *puStack_58;
  ASN1_BIT_STRING *pAStack_54;
  ASN1_BIT_STRING *pAStack_50;
  code *pcStack_4c;
  undefined4 local_38;
  undefined *local_30;
  char *local_24;
  char local_20;
  undefined local_1f;
  uchar *local_1c;
  
  puStack_58 = PTR___stack_chk_guard_006aabf0;
  local_30 = &_gp;
  local_1c = *(uchar **)PTR___stack_chk_guard_006aabf0;
  pcStack_ac = (char *)param_2;
  pAStack_b0 = param_3;
  pAStack_54 = unaff_s2;
  pAStack_50 = unaff_s3;
  puStack_a8 = unaff_s4;
  if (param_1 == (ASN1_BIT_STRING *)0x0) {
LAB_00568ca0:
    param_1 = unaff_s0;
    uVar5 = 0;
  }
  else {
    pcStack_ac = (char *)&local_24;
    pAStack_b0 = (ASN1_BIT_STRING *)&DAT_0000000a;
    iVar4 = (*(code *)PTR_strtoul_006aab38)();
    pAStack_54 = param_2;
    pAStack_50 = param_3;
    puStack_a8 = param_4;
    if (local_24 == (char *)0x0) {
      if (-1 < iVar4) {
        param_3->length = iVar4;
        goto LAB_00568cb4;
      }
LAB_00568d68:
      pAStack_b0 = (ASN1_BIT_STRING *)0xbb;
      local_38 = 399;
      pcStack_ac = (char *)0xb6;
      (**(code **)(local_30 + -0x6eb0))(0xd,0xb6,0xbb,"asn1_gen.c");
      uVar5 = 0;
    }
    else {
      if ((*local_24 != '\0') &&
         (unaff_s0 = param_1, (char *)((int)&param_2->length + (int)&param_1->length) < local_24))
      goto LAB_00568ca0;
      param_1 = (ASN1_BIT_STRING *)(local_24 + -(int)param_1);
      if (iVar4 < 0) goto LAB_00568d68;
      param_3->length = iVar4;
      if (param_2 != param_1) {
        cVar2 = *local_24;
        if (cVar2 != 'C') {
          if (cVar2 < 'D') {
            if (cVar2 == 'A') {
              uVar5 = 1;
              *param_4 = 0x40;
            }
            else {
              pcVar18 = *(code **)(local_30 + -0x6eb0);
LAB_00568d08:
              local_1f = 0;
              local_38 = 0x1b0;
              local_20 = cVar2;
              (*pcVar18)(0xd,0xb6,0xba,"asn1_gen.c");
              pAStack_b0 = (ASN1_BIT_STRING *)&local_20;
              pcStack_ac = "Char=";
              (**(code **)(local_30 + -0x6c7c))(2);
              uVar5 = 0;
            }
          }
          else if (cVar2 == 'P') {
            uVar5 = 1;
            *param_4 = 0xc0;
          }
          else {
            pcVar18 = *(code **)(local_30 + -0x6eb0);
            if (cVar2 != 'U') goto LAB_00568d08;
            *param_4 = 0;
            uVar5 = 1;
          }
          goto LAB_00568cc0;
        }
      }
LAB_00568cb4:
      uVar5 = 1;
      *param_4 = 0x80;
    }
  }
LAB_00568cc0:
  if (local_1c == *(uchar **)puStack_58) {
    return uVar5;
  }
  pcStack_4c = bitstr_cb;
  puStack_b4 = local_1c;
  (**(code **)(local_30 + -0x5328))();
  puStack_b8 = PTR___stack_chk_guard_006aabf0;
  AStack_68.type = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar17 = (ASN1_BIT_STRING *)pcStack_ac;
  pAVar11 = pAStack_b0;
  puVar8 = puStack_58;
  pAVar15 = pAStack_54;
  pAVar16 = pAStack_50;
  AStack_68.flags = (long)param_1;
  if (puStack_b4 == (uchar *)0x0) {
LAB_00568e14:
    n = pAVar17;
    uVar5 = 0;
    puStack_b4 = puVar8;
    pAStack_b0 = pAVar15;
    pcStack_ac = (char *)pAVar16;
  }
  else {
    pAVar17 = &AStack_68;
    pAVar11 = (ASN1_BIT_STRING *)&DAT_0000000a;
    n = (ASN1_BIT_STRING *)(*(code *)PTR_strtoul_006aab38)();
    pAVar15 = pAStack_b0;
    pAVar16 = (ASN1_BIT_STRING *)pcStack_ac;
    if ((((uchar *)AStack_68.length != (uchar *)0x0) &&
        (puStack_b4 = puStack_b4 + (int)pcStack_ac, *(uchar *)AStack_68.length != '\0')) &&
       (puVar8 = puStack_b4, (uchar *)AStack_68.length != puStack_b4)) goto LAB_00568e14;
    if ((int)n < 0) {
      pAVar11 = (ASN1_BIT_STRING *)0xbb;
      pAVar17 = (ASN1_BIT_STRING *)&DAT_000000b4;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb4,0xbb,"asn1_gen.c");
      puVar8 = puStack_b4;
      goto LAB_00568e14;
    }
    pAVar11 = (ASN1_BIT_STRING *)0x1;
    uVar5 = ASN1_BIT_STRING_set_bit(pAStack_b0,(int)n,1);
    if (uVar5 == 0) {
      pAVar11 = (ASN1_BIT_STRING *)&DAT_00000041;
      n = (ASN1_BIT_STRING *)&DAT_000000b4;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb4,0x41,"asn1_gen.c");
    }
    else {
      uVar5 = 1;
    }
  }
  if ((char *)AStack_68.type == *(char **)puStack_b8) {
    return uVar5;
  }
  pcVar7 = (char *)AStack_68.type;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iStack_bc = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((int)n < 1) {
    pcVar14 = (char *)0x0;
    iStack_cc = 0;
  }
  else {
    pcVar14 = pcVar7;
    if (*pcVar7 == ':') {
      pAVar17 = (ASN1_BIT_STRING *)0x0;
    }
    else {
      do {
        pcVar14 = pcVar14 + 1;
        if (pcVar14 == pcVar7 + (int)n) {
          pcVar14 = (char *)0x0;
          iStack_cc = 0;
          pAVar17 = n;
          goto LAB_00568f64;
        }
        pAVar17 = (ASN1_BIT_STRING *)(pcVar14 + -(int)pcVar7);
      } while (*pcVar14 != ':');
    }
    pcVar14 = pcVar14 + 1;
    iStack_cc = (int)n - ((int)pcVar14 - (int)pcVar7);
    n = pAVar17;
  }
  pAVar17 = n;
  if (n == (ASN1_BIT_STRING *)0xffffffff) {
    pAVar17 = (ASN1_BIT_STRING *)(*(code *)PTR_strlen_006aab30)(pcVar7);
  }
LAB_00568f64:
  tntmp_13652 = tnst_13653;
  puVar13 = (undefined4 *)tnst_13653;
  if (pAVar17 == (ASN1_BIT_STRING *)&SUB_00000004) goto LAB_00568f9c;
  do {
    do {
      tntmp_13652 = (undefined1 *)(puVar13 + 3);
      if (tntmp_13652 == tag2str_7235) goto LAB_00569024;
      ppAVar1 = (ASN1_BIT_STRING **)(puVar13 + 4);
      puVar13 = (undefined4 *)tntmp_13652;
    } while (pAVar17 != *ppAVar1);
LAB_00568f9c:
    puVar13 = (undefined4 *)tntmp_13652;
    iVar4 = (*(code *)PTR_strncmp_006aaa7c)(*(undefined4 *)tntmp_13652,pcVar7,pAVar17);
  } while (iVar4 != 0);
  puVar8 = (uchar *)puVar13[2];
  if (puVar8 == (uchar *)0xffffffff) {
LAB_00569024:
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb1,0xc2,"asn1_gen.c",0x12f);
    (*(code *)PTR_ERR_add_error_data_006a9264)(2,&DAT_0066ae9c,pcVar7);
    uVar5 = 0xffffffff;
    goto LAB_00568fe4;
  }
  uVar5 = (uint)puVar8 & 0x10000;
  if (uVar5 == 0) {
    pAVar11->data = puVar8;
    pAVar11[1].length = (int)pcVar14;
    if ((pcVar14 == (char *)0x0) && (pcVar7[(int)n] != '\0')) {
      uVar12 = 0xbd;
      uVar6 = 0x13c;
      goto LAB_00569340;
    }
    goto LAB_00568fe4;
  }
  switch(puVar8) {
  case (uchar *)0x10001:
    if (pAVar11->length != -1) {
      uVar12 = 0xb5;
      uVar6 = 0x149;
      goto LAB_00569340;
    }
    iVar4 = parse_tagging(pcVar14,iStack_cc,pAVar11,&pAVar11->type);
    if (iVar4 == 0) goto LAB_005692e4;
  default:
    uVar5 = 1;
    goto LAB_00568fe4;
  case (uchar *)0x10002:
    iVar4 = parse_tagging(pcVar14,iStack_cc,&iStack_c4,&iStack_c0);
    if (iVar4 != 0) {
      if (pAVar11->length == -1) {
        iVar4 = pAVar11[0x1a].type;
        if (iVar4 != 0x14) {
          pAVar11[0x1a].type = iVar4 + 1;
          uVar5 = 1;
          *(int *)((int)pAVar11 + iVar4 * 0x14 + 0x14) = iStack_c4;
          *(undefined4 *)((int)pAVar11 + iVar4 * 0x14 + 0x20) = 0;
          *(int *)((int)pAVar11 + iVar4 * 0x14 + 0x18) = iStack_c0;
          *(undefined4 *)((int)pAVar11 + iVar4 * 0x14 + 0x1c) = 1;
          goto LAB_00568fe4;
        }
        uVar12 = 0xae;
        uVar6 = 0x20c;
      }
      else {
        uVar12 = 0xb3;
        uVar6 = 0x206;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb0,uVar12,"asn1_gen.c",uVar6);
    }
LAB_005692e4:
    uVar5 = 0xffffffff;
    goto LAB_00568fe4;
  case (uchar *)0x10004:
    iVar9 = pAVar11[0x1a].type;
    iVar10 = pAVar11->length;
    if (iVar9 != 0x14) {
      pAVar11[0x1a].type = iVar9 + 1;
      if (iVar10 == -1) {
        iVar10 = 3;
      }
      else {
        iVar4 = pAVar11->type;
        pAVar11->length = -1;
        pAVar11->type = -1;
      }
      uVar5 = 1;
      *(int *)((int)pAVar11 + iVar9 * 0x14 + 0x18) = iVar4;
      *(int *)((int)pAVar11 + iVar9 * 0x14 + 0x14) = iVar10;
      *(undefined4 *)((int)pAVar11 + iVar9 * 0x14 + 0x1c) = 0;
      *(undefined4 *)((int)pAVar11 + iVar9 * 0x14 + 0x20) = 1;
      goto LAB_00568fe4;
    }
    break;
  case (uchar *)0x10005:
    iVar9 = pAVar11[0x1a].type;
    iVar10 = pAVar11->length;
    if (iVar9 != 0x14) {
      pAVar11[0x1a].type = iVar9 + 1;
      if (iVar10 == -1) {
        iVar10 = 4;
      }
      else {
        iVar4 = pAVar11->type;
        pAVar11->length = -1;
        pAVar11->type = -1;
      }
      uVar5 = 1;
      *(int *)((int)pAVar11 + iVar9 * 0x14 + 0x18) = iVar4;
      *(int *)((int)pAVar11 + iVar9 * 0x14 + 0x14) = iVar10;
      *(undefined4 *)((int)pAVar11 + iVar9 * 0x14 + 0x1c) = 0;
      *(undefined4 *)((int)pAVar11 + iVar9 * 0x14 + 0x20) = 0;
      goto LAB_00568fe4;
    }
    break;
  case (uchar *)0x10006:
    iVar9 = pAVar11[0x1a].type;
    iVar10 = pAVar11->length;
    if (iVar9 != 0x14) {
      pAVar11[0x1a].type = iVar9 + 1;
      if (iVar10 == -1) {
        iVar10 = 0x10;
      }
      else {
LAB_00569188:
        iVar4 = pAVar11->type;
        pAVar11->length = -1;
        pAVar11->type = -1;
      }
LAB_00569194:
      uVar5 = 1;
      *(int *)((int)pAVar11 + iVar9 * 0x14 + 0x18) = iVar4;
      *(int *)((int)pAVar11 + iVar9 * 0x14 + 0x14) = iVar10;
      *(undefined4 *)((int)pAVar11 + iVar9 * 0x14 + 0x20) = 0;
      *(undefined4 *)((int)pAVar11 + iVar9 * 0x14 + 0x1c) = 1;
      goto LAB_00568fe4;
    }
    break;
  case (uchar *)0x10007:
    iVar9 = pAVar11[0x1a].type;
    iVar10 = pAVar11->length;
    if (iVar9 != 0x14) {
      pAVar11[0x1a].type = iVar9 + 1;
      if (iVar10 != -1) goto LAB_00569188;
      iVar10 = 0x11;
      goto LAB_00569194;
    }
    break;
  case (uchar *)0x10008:
    iVar4 = (*(code *)PTR_strncmp_006aaa7c)(pcVar14,"ASCII",5);
    if (iVar4 == 0) {
      uVar5 = 1;
      pAVar11->flags = 1;
    }
    else {
      iVar4 = (*(code *)PTR_strncmp_006aaa7c)(pcVar14,&DAT_0066aeac,4);
      if (iVar4 == 0) {
        uVar5 = 1;
        pAVar11->flags = 2;
      }
      else {
        iVar4 = (*(code *)PTR_strncmp_006aaa7c)(pcVar14,&DAT_0066aeb4,3);
        if (iVar4 == 0) {
          uVar5 = 1;
          pAVar11->flags = 3;
        }
        else {
          iVar4 = (*(code *)PTR_strncmp_006aaa7c)(pcVar14,"BITLIST",3);
          if (iVar4 != 0) goto LAB_00569458;
          uVar5 = 1;
          pAVar11->flags = 4;
        }
      }
    }
    goto LAB_00568fe4;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb0,0xae,"asn1_gen.c",0x20c);
  uVar5 = 0xffffffff;
LAB_00568fe4:
  while (iStack_bc != *(int *)puVar3) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00569458:
    uVar12 = 0xc3;
    uVar6 = 0x177;
LAB_00569340:
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb1,uVar12,"asn1_gen.c",uVar6);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

