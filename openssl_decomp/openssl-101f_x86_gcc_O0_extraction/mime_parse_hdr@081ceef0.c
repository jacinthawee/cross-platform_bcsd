
_STACK * __regparm3 mime_parse_hdr(BIO *param_1)

{
  ushort *puVar1;
  byte bVar2;
  _STACK *st;
  int iVar3;
  ushort **ppuVar4;
  size_t sVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  int in_GS_OFFSET;
  void *local_440;
  byte local_420 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  st = sk_new(mime_hdr_cmp);
  local_440 = (void *)0x0;
  do {
    iVar3 = BIO_gets(param_1,(char *)local_420,0x400);
    if (iVar3 < 1) break;
    uVar6 = (uint)local_420[0];
    if (local_440 == (void *)0x0) {
LAB_081cf4c8:
      iVar3 = 1;
    }
    else {
      ppuVar4 = __ctype_b_loc();
      uVar6 = (uint)local_420[0];
      if ((*(byte *)((int)*ppuVar4 + uVar6 * 2 + 1) & 0x20) == 0) goto LAB_081cf4c8;
      iVar3 = 3;
    }
    if (((byte)uVar6 < 0xe) && ((0x2401U >> (uVar6 & 0x1f) & 1) != 0)) break;
    pbVar7 = local_420;
    pbVar9 = pbVar7;
    do {
      bVar2 = (byte)uVar6;
      pbVar8 = pbVar9;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
      switch(iVar3) {
      case 1:
        while ((char)uVar6 != ':') {
          pbVar9 = pbVar9 + 1;
          uVar6 = (uint)*pbVar9;
          if ((*pbVar9 < 0xe) && ((0x2401U >> (uVar6 & 0x1f) & 1) != 0)) goto LAB_081cf494;
        }
        *pbVar9 = 0;
        bVar2 = *pbVar7;
        if (bVar2 != 0) {
          if (bVar2 != 0x22) {
            ppuVar4 = __ctype_b_loc();
            do {
              if ((*(byte *)((int)*ppuVar4 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cf64e;
              pbVar7 = pbVar7 + 1;
              bVar2 = *pbVar7;
              if (bVar2 == 0) goto LAB_081cf300;
            } while (bVar2 != 0x22);
          }
          if ((pbVar7[1] != 0) && (pbVar7 = pbVar7 + 1, pbVar7 != (byte *)0x0)) {
LAB_081cf64e:
            sVar5 = strlen((char *)pbVar7);
            pbVar8 = pbVar7 + (sVar5 - 1);
            if (pbVar7 <= pbVar8) {
              bVar2 = *pbVar8;
              if (bVar2 != 0x22) {
                ppuVar4 = __ctype_b_loc();
                puVar1 = *ppuVar4;
                do {
                  if ((*(byte *)((int)puVar1 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cf300;
                  *pbVar8 = 0;
                  pbVar8 = pbVar8 + -1;
                  if (pbVar8 < pbVar7) goto LAB_081cf300;
                  bVar2 = *pbVar8;
                } while (bVar2 != 0x22);
              }
              if (pbVar7 != pbVar8 + -1) {
                *pbVar8 = 0;
              }
            }
          }
        }
LAB_081cf300:
        bVar2 = pbVar9[1];
        pbVar9 = pbVar9 + 1;
        pbVar7 = pbVar9;
        while( true ) {
          if ((bVar2 < 0xe) && ((0x2401U >> (bVar2 & 0x1f) & 1) != 0)) goto LAB_081cf33a;
LAB_081cf318:
          if (bVar2 == 0x3b) {
            *pbVar9 = 0;
            bVar2 = *pbVar7;
            if (bVar2 == 0) goto LAB_081cefce;
            if (bVar2 == 0x22) goto LAB_081cf720;
            ppuVar4 = __ctype_b_loc();
            goto LAB_081cf587;
          }
          if (bVar2 == 0x28) break;
          pbVar9 = pbVar9 + 1;
          bVar2 = *pbVar9;
        }
        pbVar8 = pbVar9 + 1;
        uVar6 = (uint)*pbVar8;
        pbVar9 = pbVar9 + 1;
        if ((*pbVar8 < 0xe) && ((0x2401U >> (uVar6 & 0x1f) & 1) != 0)) goto LAB_081cf494;
        iVar3 = 2;
LAB_081cf420:
        if ((char)uVar6 != ')') {
          pbVar9 = pbVar9 + 1;
          uVar6 = (uint)*pbVar9;
          if ((*pbVar9 < 0xe) && ((0x2401U >> (uVar6 & 0x1f) & 1) != 0)) goto LAB_081cf494;
          goto LAB_081cf420;
        }
        break;
      case 2:
        goto LAB_081cf318;
      case 3:
        goto switchD_081cefaf_caseD_3;
      }
      pbVar8 = pbVar9 + 1;
      uVar6 = (uint)*pbVar8;
      pbVar9 = pbVar9 + 1;
    } while ((0xd < *pbVar8) || ((0x2401U >> (uVar6 & 0x1f) & 1) == 0));
    if (iVar3 == 2) {
LAB_081cf33a:
      bVar2 = *pbVar7;
      if (bVar2 != 0) {
        if (bVar2 != 0x22) {
          ppuVar4 = __ctype_b_loc();
          do {
            if ((*(byte *)((int)*ppuVar4 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cf380;
            pbVar7 = pbVar7 + 1;
            bVar2 = *pbVar7;
            if (bVar2 == 0) goto LAB_081cf3e3;
          } while (bVar2 != 0x22);
        }
        if ((pbVar7[1] != 0) && (pbVar7 = pbVar7 + 1, pbVar7 != (byte *)0x0)) {
LAB_081cf380:
          sVar5 = strlen((char *)pbVar7);
          pbVar8 = pbVar7 + (sVar5 - 1);
          if (pbVar7 <= pbVar8) {
            bVar2 = *pbVar8;
            if (bVar2 != 0x22) {
              ppuVar4 = __ctype_b_loc();
              puVar1 = *ppuVar4;
              do {
                if ((*(byte *)((int)puVar1 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cf3e3;
                *pbVar8 = 0;
                pbVar8 = pbVar8 + -1;
                if (pbVar8 < pbVar7) goto LAB_081cf3e3;
                bVar2 = *pbVar8;
              } while (bVar2 != 0x22);
            }
            if (pbVar7 != pbVar8 + -1) {
              *pbVar8 = 0;
            }
          }
        }
      }
LAB_081cf3e3:
      local_440 = (void *)mime_hdr_new();
      sk_push(st,local_440);
    }
    else if (iVar3 == 4) {
LAB_081cf0fa:
      bVar2 = *pbVar7;
      if (bVar2 != 0) {
        if (bVar2 != 0x22) {
          ppuVar4 = __ctype_b_loc();
          do {
            if ((*(byte *)((int)*ppuVar4 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cf13c;
            pbVar7 = pbVar7 + 1;
            bVar2 = *pbVar7;
            if (bVar2 == 0) goto LAB_081cf1a1;
          } while (bVar2 != 0x22);
        }
        if ((pbVar7[1] != 0) && (pbVar7 = pbVar7 + 1, pbVar7 != (byte *)0x0)) {
LAB_081cf13c:
          sVar5 = strlen((char *)pbVar7);
          pbVar8 = pbVar7 + (sVar5 - 1);
          if (pbVar7 <= pbVar8) {
            bVar2 = *pbVar8;
            if (bVar2 != 0x22) {
              ppuVar4 = __ctype_b_loc();
              puVar1 = *ppuVar4;
              do {
                if ((*(byte *)((int)puVar1 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cf1a1;
                *pbVar8 = 0;
                pbVar8 = pbVar8 + -1;
                if (pbVar8 < pbVar7) goto LAB_081cf1a1;
                bVar2 = *pbVar8;
              } while (bVar2 != 0x22);
            }
            if (pbVar7 != pbVar8 + -1) {
              *pbVar8 = 0;
            }
          }
        }
      }
LAB_081cf1a1:
      mime_hdr_addparam_isra_1();
    }
LAB_081cf494:
  } while (pbVar9 != local_420);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return st;
  while( true ) {
    pbVar7 = pbVar7 + 1;
    bVar2 = *pbVar7;
    if (bVar2 == 0) goto LAB_081cefce;
    if (bVar2 == 0x22) break;
LAB_081cf587:
    if ((*(byte *)((int)*ppuVar4 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cf590;
  }
LAB_081cf720:
  if ((pbVar7[1] != 0) && (pbVar7 = pbVar7 + 1, pbVar7 != (byte *)0x0)) {
LAB_081cf590:
    sVar5 = strlen((char *)pbVar7);
    pbVar8 = pbVar7 + (sVar5 - 1);
    if (pbVar7 <= pbVar8) {
      bVar2 = *pbVar8;
      if (bVar2 != 0x22) {
        ppuVar4 = __ctype_b_loc();
        puVar1 = *ppuVar4;
        do {
          if ((*(byte *)((int)puVar1 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cefce;
          *pbVar8 = 0;
          pbVar8 = pbVar8 + -1;
          if (pbVar8 < pbVar7) goto LAB_081cefce;
          bVar2 = *pbVar8;
        } while (bVar2 != 0x22);
      }
      if (pbVar7 != pbVar8 + -1) {
        *pbVar8 = 0;
      }
    }
  }
LAB_081cefce:
  local_440 = (void *)mime_hdr_new();
  sk_push(st,local_440);
  bVar2 = pbVar9[1];
joined_r0x081ceff4:
  uVar6 = (uint)bVar2;
  pbVar7 = pbVar9 + 1;
  pbVar8 = pbVar7;
  if ((0xd < bVar2) || (pbVar9 = pbVar7, (0x2401U >> (uVar6 & 0x1f) & 1) == 0)) {
switchD_081cefaf_caseD_3:
    do {
      bVar2 = (byte)uVar6;
      while( true ) {
        if (bVar2 == 0x3d) {
          *pbVar8 = 0;
          bVar2 = *pbVar7;
          if (bVar2 == 0) goto LAB_081cf700;
          if (bVar2 == 0x22) goto LAB_081cf6f0;
          ppuVar4 = __ctype_b_loc();
          goto LAB_081cf05f;
        }
        pbVar8 = pbVar8 + 1;
        bVar2 = *pbVar8;
        uVar6 = (uint)bVar2;
        if (0xd < bVar2) break;
        pbVar9 = pbVar8;
        if ((0x2401U >> (uVar6 & 0x1f) & 1) != 0) goto LAB_081cf494;
      }
    } while( true );
  }
  goto LAB_081cf494;
  while( true ) {
    pbVar7 = pbVar7 + 1;
    bVar2 = *pbVar7;
    if (bVar2 == 0) goto LAB_081cf700;
    if (bVar2 == 0x22) break;
LAB_081cf05f:
    if ((*(byte *)((int)*ppuVar4 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cf066;
  }
LAB_081cf6f0:
  if ((pbVar7[1] != 0) && (pbVar7 = pbVar7 + 1, pbVar7 != (byte *)0x0)) {
LAB_081cf066:
    sVar5 = strlen((char *)pbVar7);
    pbVar9 = pbVar7 + (sVar5 - 1);
    if (pbVar7 <= pbVar9) {
      bVar2 = *pbVar9;
      if (bVar2 != 0x22) {
        ppuVar4 = __ctype_b_loc();
        puVar1 = *ppuVar4;
        do {
          if ((*(byte *)((int)puVar1 + (uint)bVar2 * 2 + 1) & 0x20) == 0) {
            uVar6 = (uint)pbVar8[1];
            pbVar9 = pbVar8 + 1;
            if (0xd < pbVar8[1]) goto LAB_081cf1eb;
            goto LAB_081cf0e8;
          }
          *pbVar9 = 0;
          pbVar9 = pbVar9 + -1;
          if (pbVar9 < pbVar7) goto LAB_081cf700;
          bVar2 = *pbVar9;
        } while (bVar2 != 0x22);
      }
      if (pbVar7 != pbVar9 + -1) {
        *pbVar9 = 0;
        bVar2 = pbVar8[1];
        goto joined_r0x081cf713;
      }
    }
  }
LAB_081cf700:
  bVar2 = pbVar8[1];
joined_r0x081cf713:
  pbVar9 = pbVar8 + 1;
  uVar6 = (uint)bVar2;
  if (bVar2 < 0xe) {
LAB_081cf0e8:
    pbVar9 = pbVar8 + 1;
    goto joined_r0x081cf0eb;
  }
LAB_081cf1eb:
  pbVar7 = pbVar8 + 1;
  if ((char)uVar6 != ';') {
    while ((char)uVar6 != '\"') {
      if ((char)uVar6 == '(') {
        pbVar8 = pbVar9 + 1;
        uVar6 = (uint)*pbVar8;
        pbVar9 = pbVar9 + 1;
        if ((*pbVar8 < 0xe) && ((0x2401U >> (uVar6 & 0x1f) & 1) != 0)) goto LAB_081cf494;
        iVar3 = 4;
        goto LAB_081cf420;
      }
      pbVar9 = pbVar9 + 1;
      bVar2 = *pbVar9;
      uVar6 = (uint)bVar2;
      if (bVar2 < 0xe) goto joined_r0x081cf0eb;
      if (bVar2 == 0x3b) goto LAB_081cf20e;
    }
    bVar2 = pbVar9[1];
    pbVar9 = pbVar9 + 1;
    while( true ) {
      if ((bVar2 < 0xe) && ((0x2401U >> (bVar2 & 0x1f) & 1) != 0)) goto LAB_081cf494;
      if (bVar2 == 0x22) break;
      pbVar9 = pbVar9 + 1;
      bVar2 = *pbVar9;
    }
    pbVar7 = pbVar9 + 1;
    uVar6 = (uint)*pbVar7;
    pbVar9 = pbVar9 + 1;
    if (*pbVar7 < 0xe) {
joined_r0x081cf0eb:
      if ((0x2401U >> (uVar6 & 0x1f) & 1) != 0) {
        pbVar7 = pbVar8 + 1;
        goto LAB_081cf0fa;
      }
    }
    goto LAB_081cf1eb;
  }
LAB_081cf20e:
  *pbVar9 = 0;
  bVar2 = *pbVar7;
  if (bVar2 != 0) {
    if (bVar2 != 0x22) {
      ppuVar4 = __ctype_b_loc();
      do {
        if ((*(byte *)((int)*ppuVar4 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cf260;
        pbVar7 = pbVar7 + 1;
        bVar2 = *pbVar7;
        if (bVar2 == 0) goto LAB_081cf2c1;
      } while (bVar2 != 0x22);
    }
    if ((pbVar7[1] != 0) && (pbVar7 = pbVar7 + 1, pbVar7 != (byte *)0x0)) {
LAB_081cf260:
      sVar5 = strlen((char *)pbVar7);
      pbVar8 = pbVar7 + (sVar5 - 1);
      if (pbVar7 <= pbVar8) {
        bVar2 = *pbVar8;
        if (bVar2 != 0x22) {
          ppuVar4 = __ctype_b_loc();
          puVar1 = *ppuVar4;
          do {
            if ((*(byte *)((int)puVar1 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cf2c1;
            *pbVar8 = 0;
            pbVar8 = pbVar8 + -1;
            if (pbVar8 < pbVar7) goto LAB_081cf2c1;
            bVar2 = *pbVar8;
          } while (bVar2 != 0x22);
        }
        if (pbVar7 != pbVar8 + -1) {
          *pbVar8 = 0;
        }
      }
    }
  }
LAB_081cf2c1:
  mime_hdr_addparam_isra_1();
  bVar2 = pbVar9[1];
  goto joined_r0x081ceff4;
}

