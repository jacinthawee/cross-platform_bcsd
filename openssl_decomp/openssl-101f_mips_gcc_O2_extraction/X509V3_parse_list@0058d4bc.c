
stack_st_CONF_VALUE * X509V3_parse_list(char *line)

{
  byte bVar1;
  code *pcVar2;
  undefined *puVar3;
  code *pcVar4;
  int *piVar5;
  int iVar6;
  code *pcVar7;
  code cVar10;
  undefined4 uVar8;
  stack_st_CONF_VALUE *psVar9;
  uint uVar11;
  byte *pbVar12;
  stack_st_CONF_VALUE *psVar13;
  code *pcVar14;
  undefined4 uVar15;
  code *pcVar16;
  byte *pbVar17;
  byte *pbVar18;
  uint uVar19;
  int iVar20;
  code *pcVar21;
  stack_st_CONF_VALUE *local_30;
  byte *local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_30 = (stack_st_CONF_VALUE *)0x0;
  local_2c = *(byte **)PTR___stack_chk_guard_006aabf0;
  pcVar4 = (code *)(*(code *)PTR_BUF_strdup_006a80dc)();
  uVar19 = (uint)(char)*pcVar4;
  pcVar16 = pcVar4;
  if ((0xd < (uVar19 & 0xff)) || ((0x2401U >> (uVar19 & 0x1f) & 1) == 0)) {
    pcVar21 = pcVar4;
LAB_0058d554:
    do {
      if (uVar19 != 0x3a) {
        if (uVar19 != 0x2c) {
          uVar19 = (uint)(char)pcVar21[1];
          pcVar21 = pcVar21 + 1;
          if (((uVar19 & 0xff) < 0xe) && ((0x2401U >> (uVar19 & 0x1f) & 1) != 0)) {
            uVar19 = (uint)(char)*pcVar16;
            break;
          }
          goto LAB_0058d554;
        }
        *pcVar21 = (code)0x0;
        uVar19 = (uint)(char)*pcVar16;
        if (uVar19 != 0) {
          piVar5 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
          iVar20 = *piVar5;
          while ((*(ushort *)(iVar20 + (uVar19 & 0xff) * 2) & 0x20) != 0) {
            uVar19 = (uint)(char)pcVar16[1];
            pcVar16 = pcVar16 + 1;
            if (uVar19 == 0) goto LAB_0058dad0;
          }
          iVar6 = (*(code *)PTR_strlen_006aab30)(pcVar16);
          pcVar7 = pcVar16 + iVar6 + -1;
          do {
            pcVar14 = pcVar7;
            if (pcVar14 == pcVar16) goto LAB_0058da20;
            pcVar7 = pcVar14 + -1;
          } while ((*(ushort *)(iVar20 + (uint)(byte)*pcVar14 * 2) & 0x20) != 0);
          if ((pcVar14 == pcVar16) || (pcVar14[1] = (code)0x0, *pcVar16 != (code)0x0)) {
LAB_0058da20:
            X509V3_add_value((char *)pcVar16,(char *)0x0,&local_30);
            pcVar16 = pcVar21 + 1;
            uVar19 = (uint)(char)pcVar21[1];
            pcVar21 = pcVar16;
            if (((uVar19 & 0xff) < 0xe) && ((0x2401U >> (uVar19 & 0x1f) & 1) != 0)) break;
            goto LAB_0058d554;
          }
        }
LAB_0058dad0:
        uVar15 = 0x6c;
        uVar8 = 0x11b;
        goto LAB_0058da70;
      }
      *pcVar21 = (code)0x0;
      uVar19 = (uint)(char)*pcVar16;
      if (uVar19 == 0) {
LAB_0058dae8:
        uVar15 = 0x6c;
        uVar8 = 0x10f;
        goto LAB_0058da70;
      }
      piVar5 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
      iVar20 = *piVar5;
      while ((*(ushort *)(iVar20 + (uVar19 & 0xff) * 2) & 0x20) != 0) {
        uVar19 = (uint)(char)pcVar16[1];
        pcVar16 = pcVar16 + 1;
        if (uVar19 == 0) goto LAB_0058dae8;
      }
      iVar6 = (*(code *)PTR_strlen_006aab30)(pcVar16);
      pcVar7 = pcVar16 + iVar6 + -1;
      if (pcVar16 + iVar6 + -1 == pcVar16) {
        cVar10 = *pcVar16;
      }
      else {
        do {
          pcVar14 = pcVar7 + -1;
          if ((*(ushort *)(iVar20 + (uint)(byte)*pcVar7 * 2) & 0x20) == 0) {
            pcVar7[1] = (code)0x0;
            break;
          }
          pcVar7 = pcVar14;
        } while (pcVar14 != pcVar16);
        cVar10 = *pcVar16;
      }
      if (cVar10 == (code)0x0) goto LAB_0058dae8;
      uVar11 = (uint)(char)pcVar21[1];
      pcVar14 = pcVar21 + 1;
      uVar19 = uVar11;
      pcVar7 = pcVar14;
      while( true ) {
        if (((uVar19 & 0xff) < 0xe) && ((0x2401U >> (uVar19 & 0x1f) & 1) != 0)) {
          if (uVar11 == 0) goto LAB_0058dafc;
          piVar5 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
          iVar20 = *piVar5;
          goto LAB_0058d7e0;
        }
        if (uVar19 == 0x2c) break;
        pcVar7 = pcVar7 + 1;
        uVar19 = (uint)(char)*pcVar7;
      }
      *pcVar7 = (code)0x0;
      uVar19 = (uint)(char)pcVar21[1];
      if (uVar19 == 0) {
LAB_0058da5c:
        uVar15 = 0x6d;
        uVar8 = 299;
        goto LAB_0058da70;
      }
      iVar20 = *piVar5;
      while ((*(ushort *)(iVar20 + (uVar19 & 0xff) * 2) & 0x20) != 0) {
        uVar19 = (uint)(char)pcVar14[1];
        pcVar14 = pcVar14 + 1;
        if (uVar19 == 0) goto LAB_0058da5c;
      }
      iVar6 = (*(code *)PTR_strlen_006aab30)(pcVar14);
      pcVar21 = pcVar14 + iVar6 + -1;
      do {
        pcVar2 = pcVar21;
        if (pcVar2 == pcVar14) goto LAB_0058d91c;
        pcVar21 = pcVar2 + -1;
      } while ((*(ushort *)(iVar20 + (uint)(byte)*pcVar2 * 2) & 0x20) != 0);
      pcVar2[1] = (code)0x0;
      if (*pcVar14 == (code)0x0) goto LAB_0058da5c;
LAB_0058d91c:
      X509V3_add_value((char *)pcVar16,(char *)pcVar14,&local_30);
      uVar19 = (uint)(char)pcVar7[1];
      pcVar16 = pcVar7 + 1;
      pcVar21 = pcVar16;
    } while ((0xd < (uVar19 & 0xff)) || ((0x2401U >> (uVar19 & 0x1f) & 1) == 0));
  }
  if (uVar19 != 0) {
    piVar5 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
    iVar20 = *piVar5;
    do {
      if ((*(ushort *)(iVar20 + (uVar19 & 0xff) * 2) & 0x20) == 0) {
        iVar6 = (*(code *)PTR_strlen_006aab30)(pcVar16);
        pcVar21 = pcVar16 + iVar6 + -1;
        if (pcVar16 + iVar6 + -1 == pcVar16) goto LAB_0058d638;
        goto LAB_0058d600;
      }
      uVar19 = (uint)(char)pcVar16[1];
      pcVar16 = pcVar16 + 1;
    } while (uVar19 != 0);
  }
LAB_0058dab8:
  uVar15 = 0x6c;
  uVar8 = 0x146;
LAB_0058da70:
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x6d,uVar15,"v3_utl.c",uVar8);
  (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar4);
  pcVar14 = X509V3_conf_free;
  (*(code *)PTR_sk_pop_free_006a8158)(local_30);
  psVar9 = (stack_st_CONF_VALUE *)0x0;
LAB_0058d65c:
  if (local_2c == *(byte **)puVar3) {
    return psVar9;
  }
  pbVar12 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (pbVar12 == (byte *)0x0) {
    return (stack_st_CONF_VALUE *)0x0;
  }
  if (pcVar14 == (code *)0x0) {
    return (stack_st_CONF_VALUE *)0x0;
  }
  psVar9 = (stack_st_CONF_VALUE *)
           (*(code *)PTR_CRYPTO_malloc_006a8108)((int)pcVar14 * 3 + 1,"v3_utl.c",0x172);
  if (psVar9 == (stack_st_CONF_VALUE *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x6f,0x41,"v3_utl.c",0x173);
    psVar9 = (stack_st_CONF_VALUE *)0x0;
  }
  else {
    psVar13 = psVar9;
    if (0 < (int)pcVar14) {
      pbVar17 = pbVar12;
      do {
        pbVar18 = pbVar17 + 1;
        *(char *)&(psVar13->stack).num = "0123456789ABCDEF"[*pbVar17 >> 4];
        bVar1 = *pbVar17;
        *(undefined *)((int)&(psVar13->stack).num + 2) = 0x3a;
        *(char *)((int)&(psVar13->stack).num + 1) = "0123456789ABCDEF"[bVar1 & 0xf];
        psVar13 = (stack_st_CONF_VALUE *)((int)&(psVar13->stack).num + 3);
        pbVar17 = pbVar18;
      } while (pbVar18 != pbVar12 + (int)pcVar14);
      psVar13 = (stack_st_CONF_VALUE *)((int)&(psVar9->stack).num + (int)pcVar14 * 3);
    }
    *(undefined *)((int)&psVar13[-1].stack.comp + 3) = 0;
  }
  return psVar9;
  while (uVar11 = (uint)(char)pcVar14[1], pcVar14 = pcVar14 + 1, uVar11 != 0) {
LAB_0058d7e0:
    if ((*(ushort *)(iVar20 + (uVar11 & 0xff) * 2) & 0x20) == 0) {
      iVar6 = (*(code *)PTR_strlen_006aab30)(pcVar14);
      pcVar21 = pcVar14 + iVar6 + -1;
      if (pcVar14 + iVar6 + -1 == pcVar14) goto LAB_0058d860;
      goto LAB_0058d82c;
    }
  }
LAB_0058dafc:
  uVar15 = 0x6d;
  uVar8 = 0x13c;
  goto LAB_0058da70;
  while (pcVar21 = pcVar7, pcVar7 != pcVar14) {
LAB_0058d82c:
    pcVar7 = pcVar21 + -1;
    if ((*(ushort *)(iVar20 + (uint)(byte)*pcVar21 * 2) & 0x20) == 0) {
      pcVar21[1] = (code)0x0;
      if (*pcVar14 == (code)0x0) goto LAB_0058dafc;
      break;
    }
  }
LAB_0058d860:
  X509V3_add_value((char *)pcVar16,(char *)pcVar14,&local_30);
  goto LAB_0058d648;
  while (pcVar21 = pcVar7, pcVar7 != pcVar16) {
LAB_0058d600:
    pcVar7 = pcVar21 + -1;
    if ((*(ushort *)(iVar20 + (uint)(byte)*pcVar21 * 2) & 0x20) == 0) {
      if ((pcVar21 != pcVar16) && (pcVar21[1] = (code)0x0, *pcVar16 == (code)0x0))
      goto LAB_0058dab8;
      break;
    }
  }
LAB_0058d638:
  pcVar14 = (code *)0x0;
  X509V3_add_value((char *)pcVar16,(char *)0x0,&local_30);
LAB_0058d648:
  (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar4);
  psVar9 = local_30;
  goto LAB_0058d65c;
}

