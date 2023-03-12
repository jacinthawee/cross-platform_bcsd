
ASN1_OBJECT * ASN1_OBJECT_create(int nid,uchar *data,int len,char *sn,char *ln)

{
  ASN1_OBJECT *pAVar1;
  int in_GS_OFFSET;
  ASN1_OBJECT local_28;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_28.flags = 0xd;
  local_28.sn = sn;
  local_28.ln = (char **)ln;
  local_28.data = data;
  local_28.nid = nid;
  local_28.length = len;
  pAVar1 = OBJ_dup(&local_28);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

