
int X509_NAME_print_ex_fp(FILE *fp,X509_NAME *nm,int indent,ulong flags)

{
  BIO *bp;
  uint uVar1;
  size_t sVar2;
  int iVar3;
  X509_NAME_ENTRY *ne;
  size_t sVar4;
  ASN1_OBJECT *o;
  ASN1_STRING *pAVar5;
  size_t sVar6;
  uint uVar7;
  char *__ptr;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  size_t __n;
  char *buf;
  int iVar12;
  int local_c4;
  int local_c0;
  size_t local_a4;
  char *local_9c;
  size_t local_90;
  undefined *local_8c;
  int local_88;
  int local_84;
  char acStack_7c [80];
  int local_2c;
  
  local_2c = __TMC_END__;
  if (flags == 0) {
    bp = BIO_new_fp(fp,0);
    if (bp != (BIO *)0x0) {
      uVar1 = X509_NAME_print(bp,nm,indent);
      BIO_free(bp);
      goto LAB_000b632e;
    }
LAB_000b632a:
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = indent & ~(indent >> 0x1f);
    if ((uVar1 != 0) && (fp != (FILE *)0x0)) {
      uVar9 = 0;
      do {
        sVar2 = fwrite(&DAT_00131dd0,1,1,fp);
        if (sVar2 != 1) goto LAB_000b632a;
        uVar9 = uVar9 + 1;
      } while (uVar9 != uVar1);
    }
    uVar9 = flags & 0xf0000;
    if (uVar9 == 0x20000) {
      local_a4 = 2;
      local_90 = 3;
      local_84 = 2;
      local_88 = 3;
      local_8c = &DAT_001621c8;
      uVar9 = 0;
      local_9c = ", ";
    }
    else if (uVar9 < 0x20001) {
      if (uVar9 != 0x10000) goto LAB_000b632a;
      local_a4 = 1;
      local_90 = 1;
      uVar9 = 0;
      local_88 = 1;
      local_84 = 1;
      local_8c = &DAT_001621cc;
      local_9c = ",";
    }
    else if (uVar9 == 0x30000) {
      local_a4 = 2;
      uVar9 = 0;
      local_90 = 3;
      local_84 = 2;
      local_88 = 3;
      local_8c = &DAT_001621c8;
      local_9c = "; ";
    }
    else {
      if (uVar9 != 0x40000) goto LAB_000b632a;
      local_a4 = 1;
      local_90 = 3;
      local_84 = 1;
      local_88 = 3;
      local_8c = &DAT_001621c8;
      local_9c = "\n";
      uVar9 = uVar1;
    }
    __ptr = " = ";
    if ((flags & 0x800000) == 0) {
      sVar2 = 1;
      __ptr = "=";
    }
    else {
      sVar2 = 3;
    }
    uVar7 = flags & 0x600000;
    iVar3 = X509_NAME_entry_count(nm);
    if (0 < iVar3) {
      iVar3 = iVar3 + -1;
      local_c0 = -1;
      local_c4 = 0;
      do {
        if ((flags & 0x100000) == 0) {
          ne = X509_NAME_get_entry(nm,local_c4);
          if (local_c0 == -1) goto LAB_000b65ac;
LAB_000b6450:
          iVar8 = ne->set;
          if (local_c0 == iVar8) {
            if (fp != (FILE *)0x0) {
              sVar4 = fwrite(local_8c,1,local_90,fp);
              if (sVar4 != local_90) goto LAB_000b632a;
              local_c0 = ne->set;
            }
            uVar1 = uVar1 + local_88;
          }
          else {
            if (fp != (FILE *)0x0) {
              sVar4 = fwrite(local_9c,1,local_a4,fp);
              if (sVar4 != local_a4) goto LAB_000b632a;
              uVar10 = 0;
              if (uVar9 != 0) {
                do {
                  sVar4 = fwrite(&DAT_00131dd0,1,1,fp);
                  if (sVar4 != 1) goto LAB_000b632a;
                  uVar10 = uVar10 + 1;
                } while (uVar10 != uVar9);
              }
              iVar8 = ne->set;
            }
            uVar1 = uVar1 + local_84 + uVar9;
            local_c0 = iVar8;
          }
        }
        else {
          ne = X509_NAME_get_entry(nm,iVar3);
          if (local_c0 != -1) goto LAB_000b6450;
LAB_000b65ac:
          local_c0 = ne->set;
        }
        o = X509_NAME_ENTRY_get_object(ne);
        pAVar5 = X509_NAME_ENTRY_get_data(ne);
        iVar8 = OBJ_obj2nid(o);
        if (uVar7 != 0x600000) {
          if (uVar7 == 0x400000 || iVar8 == 0) {
            buf = acStack_7c;
            OBJ_obj2txt(buf,0x50,o,1);
            __n = strlen(acStack_7c);
            sVar4 = 0;
          }
          else {
            __n = 0;
            if (uVar7 == 0) {
              buf = OBJ_nid2sn(iVar8);
              __n = strlen(buf);
              sVar4 = 10;
            }
            else if (uVar7 == 0x200000) {
              buf = OBJ_nid2ln(iVar8);
              __n = strlen(buf);
              sVar4 = 0x19;
            }
            else {
              buf = "";
              sVar4 = __n;
            }
          }
          if ((fp != (FILE *)0x0) && (sVar6 = fwrite(buf,1,__n,fp), sVar6 != __n))
          goto LAB_000b632a;
          if (((int)__n < (int)sVar4) && ((flags & 0x2000000) != 0)) {
            iVar12 = sVar4 - __n;
            if ((0 < iVar12) && (fp != (FILE *)0x0)) {
              iVar11 = 0;
              do {
                sVar4 = fwrite(&DAT_00131dd0,1,1,fp);
                if (sVar4 != 1) goto LAB_000b632a;
                iVar11 = iVar11 + 1;
              } while (iVar11 != iVar12);
            }
            uVar1 = uVar1 + iVar12;
          }
          if ((fp != (FILE *)0x0) && (sVar4 = fwrite(__ptr,1,sVar2,fp), sVar2 != sVar4))
          goto LAB_000b632a;
          uVar1 = uVar1 + __n + sVar2;
        }
        uVar10 = 0;
        if (iVar8 == 0) {
          if ((flags & 0x1000000) == 0) {
            uVar10 = 0;
          }
          else {
            uVar10 = 0x80;
          }
        }
        iVar8 = do_print_ex_constprop_3(fp,uVar10 | flags,pAVar5);
        if (iVar8 < 0) goto LAB_000b632a;
        iVar3 = iVar3 + -1;
        uVar1 = uVar1 + iVar8;
        local_c4 = local_c4 + 1;
      } while (iVar3 != -1);
    }
  }
LAB_000b632e:
  if (local_2c == __TMC_END__) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

