
stack_st_CONF_VALUE * X509V3_parse_list(char *line)

{
  byte bVar1;
  code *pcVar2;
  undefined *puVar3;
  code *pcVar4;
  int *piVar5;
  int iVar6;
  code cVar9;
  undefined4 uVar7;
  stack_st_CONF_VALUE *psVar8;
  code *pcVar10;
  uint uVar11;
  byte *pbVar12;
  stack_st_CONF_VALUE *psVar13;
  int iVar14;
  undefined4 uVar15;
  code *pcVar16;
  code *pcVar17;
  byte *pbVar18;
  byte *pbVar19;
  uint uVar20;
  code *pcVar21;
  stack_st_CONF_VALUE *local_30;
  byte *local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_30 = (stack_st_CONF_VALUE *)0x0;
  local_2c = *(byte **)PTR___stack_chk_guard_006a9ae8;
  pcVar4 = (code *)(*(code *)PTR_BUF_strdup_006a6fdc)();
  if (pcVar4 != (code *)0x0) {
    uVar20 = (uint)(char)*pcVar4;
    pcVar17 = pcVar4;
    if ((0xd < (uVar20 & 0xff)) || ((0x2401U >> (uVar20 & 0x1f) & 1) == 0)) {
      pcVar10 = pcVar4;
joined_r0x0058a7e4:
      do {
        if (uVar20 == 0x3a) {
          *pcVar10 = (code)0x0;
          uVar20 = (uint)(char)*pcVar17;
          if (uVar20 != 0) {
            piVar5 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
            iVar14 = *piVar5;
            while ((*(ushort *)(iVar14 + (uVar20 & 0xff) * 2) & 0x20) != 0) {
              uVar20 = (uint)(char)pcVar17[1];
              pcVar17 = pcVar17 + 1;
              if (uVar20 == 0) goto LAB_0058ad70;
            }
            iVar6 = (*(code *)PTR_strlen_006a9a24)(pcVar17);
            pcVar16 = pcVar17 + iVar6 + -1;
            if (pcVar17 + iVar6 + -1 == pcVar17) {
              cVar9 = *pcVar17;
            }
            else {
              do {
                pcVar21 = pcVar16 + -1;
                if ((*(ushort *)(iVar14 + (uint)(byte)*pcVar16 * 2) & 0x20) == 0) {
                  if (pcVar16 != pcVar17) {
                    pcVar16[1] = (code)0x0;
                  }
                  break;
                }
                pcVar16 = pcVar21;
              } while (pcVar21 != pcVar17);
              cVar9 = *pcVar17;
            }
            if (cVar9 != (code)0x0) {
              uVar11 = (uint)(char)pcVar10[1];
              pcVar21 = pcVar10 + 1;
              uVar20 = uVar11;
              pcVar16 = pcVar21;
              if ((0xd < (uVar11 & 0xff)) || ((0x2401U >> (uVar11 & 0x1f) & 1) == 0)) {
                while (uVar20 != 0x2c) {
                  pcVar16 = pcVar16 + 1;
                  uVar20 = (uint)(char)*pcVar16;
                  if (((uVar20 & 0xff) < 0xe) && ((0x2401U >> (uVar20 & 0x1f) & 1) != 0))
                  goto LAB_0058a944;
                }
                *pcVar16 = (code)0x0;
                uVar20 = (uint)(char)pcVar10[1];
                if (uVar20 != 0) {
                  iVar14 = *piVar5;
                  while ((*(ushort *)(iVar14 + (uVar20 & 0xff) * 2) & 0x20) != 0) {
                    uVar20 = (uint)(char)pcVar21[1];
                    pcVar21 = pcVar21 + 1;
                    if (uVar20 == 0) goto LAB_0058ace4;
                  }
                  iVar6 = (*(code *)PTR_strlen_006a9a24)(pcVar21);
                  pcVar10 = pcVar21 + iVar6 + -1;
                  do {
                    pcVar2 = pcVar10;
                    if (pcVar2 == pcVar21) goto LAB_0058acac;
                    pcVar10 = pcVar2 + -1;
                  } while ((*(ushort *)(iVar14 + (uint)(byte)*pcVar2 * 2) & 0x20) != 0);
                  if ((pcVar21 == pcVar2) || (pcVar2[1] = (code)0x0, *pcVar21 != (code)0x0)) {
LAB_0058acac:
                    X509V3_add_value((char *)pcVar17,(char *)pcVar21,&local_30);
                    cVar9 = pcVar16[1];
                    pcVar10 = pcVar16;
                    goto joined_r0x0058acd0;
                  }
                }
LAB_0058ace4:
                uVar15 = 0x6d;
                uVar7 = 0x150;
                goto LAB_0058acf8;
              }
LAB_0058a944:
              if (uVar11 == 0) goto LAB_0058ad8c;
              piVar5 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
              iVar14 = *piVar5;
              goto LAB_0058a974;
            }
          }
LAB_0058ad70:
          uVar15 = 0x6c;
          uVar7 = 0x132;
          goto LAB_0058acf8;
        }
        if (uVar20 != 0x2c) {
          uVar20 = (uint)(char)pcVar10[1];
          pcVar10 = pcVar10 + 1;
          if (((uVar20 & 0xff) < 0xe) && ((0x2401U >> (uVar20 & 0x1f) & 1) != 0)) {
            uVar20 = (uint)(char)*pcVar17;
            break;
          }
          goto joined_r0x0058a7e4;
        }
        *pcVar10 = (code)0x0;
        uVar20 = (uint)(char)*pcVar17;
        if (uVar20 == 0) {
LAB_0058ad58:
          uVar15 = 0x6c;
          uVar7 = 0x13f;
          goto LAB_0058acf8;
        }
        piVar5 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
        iVar14 = *piVar5;
        while ((*(ushort *)(iVar14 + (uVar20 & 0xff) * 2) & 0x20) != 0) {
          uVar20 = (uint)(char)pcVar17[1];
          pcVar17 = pcVar17 + 1;
          if (uVar20 == 0) goto LAB_0058ad58;
        }
        iVar6 = (*(code *)PTR_strlen_006a9a24)(pcVar17);
        pcVar16 = pcVar17 + iVar6 + -1;
        do {
          pcVar21 = pcVar16;
          if (pcVar21 == pcVar17) goto LAB_0058aac0;
          pcVar16 = pcVar21 + -1;
        } while ((*(ushort *)(iVar14 + (uint)(byte)*pcVar21 * 2) & 0x20) != 0);
        pcVar21[1] = (code)0x0;
        if (*pcVar17 == (code)0x0) goto LAB_0058ad58;
LAB_0058aac0:
        X509V3_add_value((char *)pcVar17,(char *)0x0,&local_30);
        cVar9 = pcVar10[1];
joined_r0x0058acd0:
        uVar20 = (uint)(char)cVar9;
        pcVar17 = pcVar10 + 1;
        pcVar10 = pcVar17;
      } while ((0xd < (uVar20 & 0xff)) || ((0x2401U >> (uVar20 & 0x1f) & 1) == 0));
    }
    if (uVar20 != 0) {
      piVar5 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
      iVar14 = *piVar5;
      do {
        if ((*(ushort *)(iVar14 + (uVar20 & 0xff) * 2) & 0x20) == 0) {
          iVar6 = (*(code *)PTR_strlen_006a9a24)(pcVar17);
          pcVar10 = pcVar17 + iVar6 + -1;
          goto joined_r0x0058ab50;
        }
        uVar20 = (uint)(char)pcVar17[1];
        pcVar17 = pcVar17 + 1;
      } while (uVar20 != 0);
    }
    goto LAB_0058ad40;
  }
  uVar15 = 0x41;
  uVar7 = 0x121;
  goto LAB_0058acf8;
  while (uVar11 = (uint)(char)pcVar21[1], pcVar21 = pcVar21 + 1, uVar11 != 0) {
LAB_0058a974:
    if ((*(ushort *)(iVar14 + (uVar11 & 0xff) * 2) & 0x20) == 0) {
      iVar6 = (*(code *)PTR_strlen_006a9a24)(pcVar21);
      pcVar10 = pcVar21 + iVar6 + -1;
      goto joined_r0x0058a9a8;
    }
  }
  goto LAB_0058ad8c;
  while (pcVar10 = pcVar16 + -1, (*(ushort *)(iVar14 + (uint)(byte)*pcVar16 * 2) & 0x20) != 0) {
joined_r0x0058a9a8:
    pcVar16 = pcVar10;
    if (pcVar16 == pcVar21) goto LAB_0058a9f4;
  }
  pcVar16[1] = (code)0x0;
  if (*pcVar21 != (code)0x0) {
LAB_0058a9f4:
    X509V3_add_value((char *)pcVar17,(char *)pcVar21,&local_30);
    goto LAB_0058abac;
  }
LAB_0058ad8c:
  uVar15 = 0x6d;
  uVar7 = 0x162;
  goto LAB_0058acf8;
  while (pcVar10 = pcVar16 + -1, (*(ushort *)(iVar14 + (uint)(byte)*pcVar16 * 2) & 0x20) != 0) {
joined_r0x0058ab50:
    pcVar16 = pcVar10;
    if (pcVar16 == pcVar17) goto LAB_0058ab9c;
  }
  pcVar16[1] = (code)0x0;
  if (*pcVar17 != (code)0x0) {
LAB_0058ab9c:
    pcVar21 = (code *)0x0;
    X509V3_add_value((char *)pcVar17,(char *)0x0,&local_30);
LAB_0058abac:
    (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar4);
    psVar8 = local_30;
    goto LAB_0058abc0;
  }
LAB_0058ad40:
  uVar15 = 0x6c;
  uVar7 = 0x16c;
LAB_0058acf8:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x6d,uVar15,"v3_utl.c",uVar7);
  (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar4);
  pcVar21 = X509V3_conf_free;
  (*(code *)PTR_sk_pop_free_006a7058)(local_30);
  psVar8 = (stack_st_CONF_VALUE *)0x0;
LAB_0058abc0:
  if (local_2c == *(byte **)puVar3) {
    return psVar8;
  }
  pbVar12 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (pbVar12 != (byte *)0x0) {
    if (pcVar21 != (code *)0x0) {
      psVar8 = (stack_st_CONF_VALUE *)
               (*(code *)PTR_CRYPTO_malloc_006a7008)((int)pcVar21 * 3 + 1,"v3_utl.c",0x19f);
      if (psVar8 == (stack_st_CONF_VALUE *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x6f,0x41,"v3_utl.c",0x1a0);
        psVar8 = (stack_st_CONF_VALUE *)0x0;
      }
      else {
        psVar13 = psVar8;
        if (0 < (int)pcVar21) {
          pbVar18 = pbVar12;
          do {
            pbVar19 = pbVar18 + 1;
            *(char *)&(psVar13->stack).num = "0123456789ABCDEF"[*pbVar18 >> 4];
            bVar1 = *pbVar18;
            *(undefined *)((int)&(psVar13->stack).num + 2) = 0x3a;
            *(char *)((int)&(psVar13->stack).num + 1) = "0123456789ABCDEF"[bVar1 & 0xf];
            psVar13 = (stack_st_CONF_VALUE *)((int)&(psVar13->stack).num + 3);
            pbVar18 = pbVar19;
          } while (pbVar19 != pbVar12 + (int)pcVar21);
          psVar13 = (stack_st_CONF_VALUE *)((int)&(psVar8->stack).num + (int)pcVar21 * 3);
        }
        *(undefined *)((int)&psVar13[-1].stack.comp + 3) = 0;
      }
      return psVar8;
    }
    return (stack_st_CONF_VALUE *)0x0;
  }
  return (stack_st_CONF_VALUE *)0x0;
}

