
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
  byte *__s;
  byte *pbVar8;
  int in_GS_OFFSET;
  void *local_444;
  byte local_420;
  byte local_41f [1023];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  st = sk_new(mime_hdr_cmp);
  if (st == (_STACK *)0x0) {
    st = (_STACK *)0x0;
  }
  else {
    local_444 = (void *)0x0;
    do {
      iVar3 = BIO_gets(param_1,(char *)&local_420,0x400);
      if (iVar3 < 1) break;
      uVar6 = (uint)local_420;
      if (local_444 == (void *)0x0) {
LAB_081ce3e8:
        iVar3 = 1;
      }
      else {
        ppuVar4 = __ctype_b_loc();
        uVar6 = (uint)local_420;
        if ((*(byte *)((int)*ppuVar4 + uVar6 * 2 + 1) & 0x20) == 0) goto LAB_081ce3e8;
        iVar3 = 3;
      }
      if (((byte)uVar6 < 0xe) && ((0x2401U >> (uVar6 & 0x1f) & 1) != 0)) break;
      __s = &local_420;
      pbVar7 = __s;
      do {
        bVar2 = (byte)uVar6;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
        switch(iVar3) {
        case 1:
          while ((char)uVar6 != ':') {
            while( true ) {
              pbVar7 = pbVar7 + 1;
              bVar2 = *pbVar7;
              uVar6 = (uint)bVar2;
              if (0xd < bVar2) break;
              if ((0x2401U >> (uVar6 & 0x1f) & 1) != 0) goto LAB_081ce3ac;
              if (bVar2 == 0x3a) goto LAB_081ce2b9;
            }
          }
LAB_081ce2b9:
          *pbVar7 = 0;
          bVar2 = *__s;
          if (bVar2 == 0) {
LAB_081ce5a8:
            bVar2 = pbVar7[1];
            pbVar7 = pbVar7 + 1;
            __s = pbVar7;
          }
          else {
            if (bVar2 != 0x22) {
              ppuVar4 = __ctype_b_loc();
              do {
                if ((*(byte *)((int)*ppuVar4 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081ce310;
                __s = __s + 1;
                bVar2 = *__s;
                if (bVar2 == 0) goto LAB_081ce5a8;
              } while (bVar2 != 0x22);
            }
            if ((__s[1] == 0) || (__s = __s + 1, __s == (byte *)0x0)) goto LAB_081ce5a8;
LAB_081ce310:
            sVar5 = strlen((char *)__s);
            pbVar8 = __s + (sVar5 - 1);
            if (pbVar8 < __s) goto LAB_081ce5a8;
            bVar2 = *pbVar8;
            if (bVar2 != 0x22) {
              ppuVar4 = __ctype_b_loc();
              puVar1 = *ppuVar4;
              do {
                if ((*(byte *)((int)puVar1 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cde3e;
                *pbVar8 = 0;
                pbVar8 = pbVar8 + -1;
                if (pbVar8 < __s) goto LAB_081ce5a8;
                bVar2 = *pbVar8;
              } while (bVar2 != 0x22);
            }
            if (__s == pbVar8 + -1) goto LAB_081ce5a8;
            *pbVar8 = 0;
LAB_081cde3e:
            bVar2 = pbVar7[1];
            pbVar7 = pbVar7 + 1;
            __s = pbVar7;
          }
          while( true ) {
            if ((bVar2 < 0xe) && ((0x2401U >> (bVar2 & 0x1f) & 1) != 0)) goto LAB_081cde6f;
switchD_081cde21_caseD_2:
            if (bVar2 == 0x3b) {
              *pbVar7 = 0;
              bVar2 = *__s;
              if (bVar2 == 0) goto LAB_081ce521;
              if (bVar2 == 0x22) goto LAB_081ce5e0;
              ppuVar4 = __ctype_b_loc();
              goto LAB_081ce4a7;
            }
            if (bVar2 == 0x28) break;
            pbVar7 = pbVar7 + 1;
            bVar2 = *pbVar7;
          }
          pbVar8 = pbVar7 + 1;
          uVar6 = (uint)*pbVar8;
          pbVar7 = pbVar7 + 1;
          if ((*pbVar8 < 0xe) && ((0x2401U >> (uVar6 & 0x1f) & 1) != 0)) goto LAB_081ce3ac;
          iVar3 = 2;
LAB_081ce050:
          if ((char)uVar6 != ')') {
            pbVar7 = pbVar7 + 1;
            uVar6 = (uint)*pbVar7;
            if ((*pbVar7 < 0xe) && ((0x2401U >> (uVar6 & 0x1f) & 1) != 0)) goto LAB_081ce3ac;
            goto LAB_081ce050;
          }
          break;
        case 2:
          goto switchD_081cde21_caseD_2;
        case 3:
          pbVar8 = pbVar7;
          goto joined_r0x081ce194;
        }
        pbVar8 = pbVar7 + 1;
        uVar6 = (uint)*pbVar8;
        pbVar7 = pbVar7 + 1;
      } while ((0xd < *pbVar8) || ((0x2401U >> (uVar6 & 0x1f) & 1) == 0));
      if (iVar3 == 2) {
LAB_081cde6f:
        bVar2 = *__s;
        if (bVar2 != 0) {
          if (bVar2 != 0x22) {
            ppuVar4 = __ctype_b_loc();
            do {
              if ((*(byte *)((int)*ppuVar4 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cdeb4;
              __s = __s + 1;
              bVar2 = *__s;
              if (bVar2 == 0) goto LAB_081cdf1f;
            } while (bVar2 != 0x22);
          }
          if ((__s[1] != 0) && (__s = __s + 1, __s != (byte *)0x0)) {
LAB_081cdeb4:
            sVar5 = strlen((char *)__s);
            pbVar8 = __s + (sVar5 - 1);
            if (__s <= pbVar8) {
              bVar2 = *pbVar8;
              if (bVar2 != 0x22) {
                ppuVar4 = __ctype_b_loc();
                puVar1 = *ppuVar4;
                do {
                  if ((*(byte *)((int)puVar1 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cdf1f;
                  *pbVar8 = 0;
                  pbVar8 = pbVar8 + -1;
                  if (pbVar8 < __s) goto LAB_081cdf1f;
                  bVar2 = *pbVar8;
                } while (bVar2 != 0x22);
              }
              if (__s != pbVar8 + -1) {
                *pbVar8 = 0;
              }
            }
          }
        }
LAB_081cdf1f:
        local_444 = (void *)mime_hdr_new();
        sk_push(st,local_444);
      }
      else if (iVar3 == 4) {
LAB_081cdf87:
        bVar2 = *__s;
        if (bVar2 != 0) {
          if (bVar2 != 0x22) {
            ppuVar4 = __ctype_b_loc();
            do {
              if ((*(byte *)((int)*ppuVar4 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cdfcc;
              __s = __s + 1;
              bVar2 = *__s;
              if (bVar2 == 0) goto LAB_081ce02f;
            } while (bVar2 != 0x22);
          }
          if ((__s[1] != 0) && (__s = __s + 1, __s != (byte *)0x0)) {
LAB_081cdfcc:
            sVar5 = strlen((char *)__s);
            pbVar8 = __s + (sVar5 - 1);
            if (__s <= pbVar8) {
              bVar2 = *pbVar8;
              if (bVar2 != 0x22) {
                ppuVar4 = __ctype_b_loc();
                puVar1 = *ppuVar4;
                do {
                  if ((*(byte *)((int)puVar1 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081ce02f;
                  *pbVar8 = 0;
                  pbVar8 = pbVar8 + -1;
                  if (pbVar8 < __s) goto LAB_081ce02f;
                  bVar2 = *pbVar8;
                } while (bVar2 != 0x22);
              }
              if (__s != pbVar8 + -1) {
                *pbVar8 = 0;
              }
            }
          }
        }
LAB_081ce02f:
        mime_hdr_addparam_isra_1();
      }
LAB_081ce3ac:
    } while (pbVar7 != &local_420);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return st;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    __s = __s + 1;
    bVar2 = *__s;
    if (bVar2 == 0) goto LAB_081ce521;
    if (bVar2 == 0x22) break;
LAB_081ce4a7:
    if ((*(byte *)((int)*ppuVar4 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081ce4b0;
  }
LAB_081ce5e0:
  if ((__s[1] != 0) && (__s = __s + 1, __s != (byte *)0x0)) {
LAB_081ce4b0:
    sVar5 = strlen((char *)__s);
    pbVar8 = __s + (sVar5 - 1);
    if (__s <= pbVar8) {
      bVar2 = *pbVar8;
      if (bVar2 != 0x22) {
        ppuVar4 = __ctype_b_loc();
        puVar1 = *ppuVar4;
        do {
          if ((*(byte *)((int)puVar1 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081ce521;
          *pbVar8 = 0;
          pbVar8 = pbVar8 + -1;
          if (pbVar8 < __s) goto LAB_081ce521;
          bVar2 = *pbVar8;
        } while (bVar2 != 0x22);
      }
      if (__s != pbVar8 + -1) {
        *pbVar8 = 0;
      }
    }
  }
LAB_081ce521:
  local_444 = (void *)mime_hdr_new();
  sk_push(st,local_444);
  bVar2 = pbVar7[1];
joined_r0x081ce545:
  pbVar7 = pbVar7 + 1;
  pbVar8 = pbVar7;
  __s = pbVar7;
  if ((0xd < bVar2) || ((0x2401U >> (bVar2 & 0x1f) & 1) == 0)) {
joined_r0x081ce194:
    while (bVar2 != 0x3d) {
      pbVar7 = pbVar8 + 1;
      bVar2 = *pbVar7;
      pbVar8 = pbVar7;
      if ((bVar2 < 0xe) && ((0x2401U >> (bVar2 & 0x1f) & 1) != 0)) goto LAB_081ce3ac;
    }
    *pbVar8 = 0;
    bVar2 = *__s;
    if (bVar2 == 0) {
LAB_081ce578:
      bVar2 = pbVar8[1];
    }
    else {
      if (bVar2 != 0x22) {
        ppuVar4 = __ctype_b_loc();
        do {
          if ((*(byte *)((int)*ppuVar4 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081ce1f0;
          __s = __s + 1;
          bVar2 = *__s;
          if (bVar2 == 0) goto LAB_081ce578;
        } while (bVar2 != 0x22);
      }
      if ((__s[1] == 0) || (__s = __s + 1, __s == (byte *)0x0)) goto LAB_081ce578;
LAB_081ce1f0:
      sVar5 = strlen((char *)__s);
      pbVar7 = __s + (sVar5 - 1);
      if (pbVar7 < __s) goto LAB_081ce578;
      bVar2 = *pbVar7;
      if (bVar2 != 0x22) {
        ppuVar4 = __ctype_b_loc();
        puVar1 = *ppuVar4;
        do {
          if ((*(byte *)((int)puVar1 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081cdf4e;
          *pbVar7 = 0;
          pbVar7 = pbVar7 + -1;
          if (pbVar7 < __s) goto LAB_081ce578;
          bVar2 = *pbVar7;
        } while (bVar2 != 0x22);
      }
      if (__s == pbVar7 + -1) goto LAB_081ce578;
      *pbVar7 = 0;
LAB_081cdf4e:
      bVar2 = pbVar8[1];
    }
    pbVar7 = pbVar8 + 1;
    uVar6 = (uint)bVar2;
    if (bVar2 < 0xe) goto LAB_081cdf82;
LAB_081cdf60:
    do {
      __s = pbVar8 + 1;
      bVar2 = (byte)uVar6;
      do {
        if (bVar2 == 0x3b) {
          *pbVar7 = 0;
          bVar2 = *__s;
          if (bVar2 == 0) goto LAB_081ce171;
          if (bVar2 == 0x22) goto LAB_081ce5c0;
          ppuVar4 = __ctype_b_loc();
          goto LAB_081ce0f7;
        }
        if ((char)uVar6 != '\"') {
          if ((char)uVar6 == '(') {
            pbVar8 = pbVar7 + 1;
            uVar6 = (uint)*pbVar8;
            pbVar7 = pbVar7 + 1;
            if ((*pbVar8 < 0xe) && ((0x2401U >> (uVar6 & 0x1f) & 1) != 0)) goto LAB_081ce3ac;
            iVar3 = 4;
            goto LAB_081ce050;
          }
          pbVar7 = pbVar7 + 1;
          uVar6 = (uint)*pbVar7;
          if (0xd < *pbVar7) goto LAB_081cdf60;
          break;
        }
        bVar2 = pbVar7[1];
        pbVar7 = pbVar7 + 1;
        while( true ) {
          if ((bVar2 < 0xe) && ((0x2401U >> (bVar2 & 0x1f) & 1) != 0)) goto LAB_081ce3ac;
          if (bVar2 == 0x22) break;
          pbVar7 = pbVar7 + 1;
          bVar2 = *pbVar7;
        }
        bVar2 = pbVar7[1];
        uVar6 = (uint)bVar2;
        pbVar7 = pbVar7 + 1;
      } while (0xd < bVar2);
LAB_081cdf82:
      __s = pbVar8 + 1;
    } while ((0x2401U >> (uVar6 & 0x1f) & 1) == 0);
    goto LAB_081cdf87;
  }
  goto LAB_081ce3ac;
  while( true ) {
    __s = __s + 1;
    bVar2 = *__s;
    if (bVar2 == 0) goto LAB_081ce171;
    if (bVar2 == 0x22) break;
LAB_081ce0f7:
    if ((*(byte *)((int)*ppuVar4 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081ce100;
  }
LAB_081ce5c0:
  if ((__s[1] != 0) && (__s = __s + 1, __s != (byte *)0x0)) {
LAB_081ce100:
    sVar5 = strlen((char *)__s);
    pbVar8 = __s + (sVar5 - 1);
    if (__s <= pbVar8) {
      bVar2 = *pbVar8;
      if (bVar2 != 0x22) {
        ppuVar4 = __ctype_b_loc();
        puVar1 = *ppuVar4;
        do {
          if ((*(byte *)((int)puVar1 + (uint)bVar2 * 2 + 1) & 0x20) == 0) goto LAB_081ce171;
          *pbVar8 = 0;
          pbVar8 = pbVar8 + -1;
          if (pbVar8 < __s) goto LAB_081ce171;
          bVar2 = *pbVar8;
        } while (bVar2 != 0x22);
      }
      if (__s != pbVar8 + -1) {
        *pbVar8 = 0;
      }
    }
  }
LAB_081ce171:
  mime_hdr_addparam_isra_1();
  bVar2 = pbVar7[1];
  goto joined_r0x081ce545;
}

