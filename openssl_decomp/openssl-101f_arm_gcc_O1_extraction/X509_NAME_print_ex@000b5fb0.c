
int X509_NAME_print_ex(BIO *out,X509_NAME *nm,int indent,ulong flags)

{
  int iVar1;
  int iVar2;
  X509_NAME_ENTRY *ne;
  ASN1_OBJECT *o;
  ASN1_STRING *pAVar3;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  char *data;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  char *buf;
  int iVar11;
  size_t len;
  int iVar12;
  size_t sVar13;
  int local_bc;
  int local_b8;
  int local_9c;
  char *local_94;
  int local_88;
  undefined *local_84;
  char acStack_7c [80];
  int local_2c;
  
  local_2c = __TMC_END__;
  if (flags == 0) {
    uVar8 = X509_NAME_print(out,nm,indent);
    goto LAB_000b5ff4;
  }
  uVar8 = indent & ~(indent >> 0x1f);
  if ((uVar8 != 0) && (out != (BIO *)0x0)) {
    uVar9 = 0;
    do {
      iVar1 = BIO_write(out,&DAT_00131dd0,1);
      if (iVar1 != 1) goto LAB_000b5ff0;
      uVar9 = uVar9 + 1;
    } while (uVar9 != uVar8);
  }
  uVar9 = flags & 0xf0000;
  if (uVar9 == 0x20000) {
    local_84 = &DAT_001621c8;
    local_94 = ", ";
    local_88 = 3;
    uVar9 = 0;
    local_9c = 2;
  }
  else if (uVar9 < 0x20001) {
    if (uVar9 != 0x10000) {
LAB_000b5ff0:
      uVar8 = 0xffffffff;
      goto LAB_000b5ff4;
    }
    local_88 = 1;
    local_9c = 1;
    uVar9 = 0;
    local_84 = &DAT_001621cc;
    local_94 = ",";
  }
  else if (uVar9 == 0x30000) {
    uVar9 = 0;
    local_84 = &DAT_001621c8;
    local_94 = "; ";
    local_88 = 3;
    local_9c = 2;
  }
  else {
    if (uVar9 != 0x40000) goto LAB_000b5ff0;
    local_84 = &DAT_001621c8;
    local_94 = "\n";
    local_88 = 3;
    local_9c = 1;
    uVar9 = uVar8;
  }
  data = " = ";
  if ((flags & 0x800000) == 0) {
    iVar1 = 1;
    data = "=";
  }
  else {
    iVar1 = 3;
  }
  uVar6 = flags & 0x600000;
  iVar2 = X509_NAME_entry_count(nm);
  if (0 < iVar2) {
    iVar2 = iVar2 + -1;
    local_b8 = -1;
    local_bc = 0;
    do {
      if ((flags & 0x100000) == 0) {
        ne = X509_NAME_get_entry(nm,local_bc);
        if (local_b8 == -1) goto LAB_000b6244;
LAB_000b60ea:
        iVar7 = ne->set;
        if (local_b8 == iVar7) {
          if (out != (BIO *)0x0) {
            iVar7 = BIO_write(out,local_84,local_88);
            if (local_88 != iVar7) goto LAB_000b5ff0;
            local_b8 = ne->set;
          }
          uVar8 = uVar8 + local_88;
        }
        else {
          if (out != (BIO *)0x0) {
            iVar7 = BIO_write(out,local_94,local_9c);
            if (local_9c != iVar7) goto LAB_000b5ff0;
            uVar10 = 0;
            if (uVar9 != 0) {
              do {
                iVar7 = BIO_write(out,&DAT_00131dd0,1);
                if (iVar7 != 1) goto LAB_000b5ff0;
                uVar10 = uVar10 + 1;
              } while (uVar10 != uVar9);
            }
            iVar7 = ne->set;
          }
          uVar8 = uVar8 + local_9c + uVar9;
          local_b8 = iVar7;
        }
      }
      else {
        ne = X509_NAME_get_entry(nm,iVar2);
        if (local_b8 != -1) goto LAB_000b60ea;
LAB_000b6244:
        local_b8 = ne->set;
      }
      o = X509_NAME_ENTRY_get_object(ne);
      pAVar3 = X509_NAME_ENTRY_get_data(ne);
      iVar7 = OBJ_obj2nid(o);
      if (uVar6 != 0x600000) {
        if (uVar6 == 0x400000 || iVar7 == 0) {
          buf = acStack_7c;
          OBJ_obj2txt(buf,0x50,o,1);
          sVar13 = 0;
          len = strlen(acStack_7c);
        }
        else {
          len = 0;
          if (uVar6 == 0) {
            buf = OBJ_nid2sn(iVar7);
            sVar13 = 10;
            len = strlen(buf);
          }
          else if (uVar6 == 0x200000) {
            buf = OBJ_nid2ln(iVar7);
            sVar13 = 0x19;
            len = strlen(buf);
          }
          else {
            buf = "";
            sVar13 = len;
          }
        }
        if ((out != (BIO *)0x0) && (sVar4 = BIO_write(out,buf,len), len != sVar4))
        goto LAB_000b5ff0;
        if (((int)len < (int)sVar13) && ((flags & 0x2000000) != 0)) {
          iVar12 = sVar13 - len;
          if ((0 < iVar12) && (out != (BIO *)0x0)) {
            iVar11 = 0;
            do {
              iVar5 = BIO_write(out,&DAT_00131dd0,1);
              if (iVar5 != 1) goto LAB_000b5ff0;
              iVar11 = iVar11 + 1;
            } while (iVar11 != iVar12);
          }
          uVar8 = uVar8 + iVar12;
        }
        if ((out != (BIO *)0x0) && (iVar12 = BIO_write(out,data,iVar1), iVar1 != iVar12))
        goto LAB_000b5ff0;
        uVar8 = uVar8 + len + iVar1;
      }
      uVar10 = 0;
      if (iVar7 == 0) {
        if ((flags & 0x1000000) == 0) {
          uVar10 = 0;
        }
        else {
          uVar10 = 0x80;
        }
      }
      iVar7 = do_print_ex_constprop_2(out,uVar10 | flags,pAVar3);
      if (iVar7 < 0) goto LAB_000b5ff0;
      iVar2 = iVar2 + -1;
      uVar8 = uVar8 + iVar7;
      local_bc = local_bc + 1;
    } while (iVar2 != -1);
  }
LAB_000b5ff4:
  if (local_2c == __TMC_END__) {
    return uVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

