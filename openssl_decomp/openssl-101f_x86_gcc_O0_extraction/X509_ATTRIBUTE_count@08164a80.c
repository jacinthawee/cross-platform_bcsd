
int X509_ATTRIBUTE_count(X509_ATTRIBUTE *attr)

{
  int iVar1;
  
  if (attr->single != 0) {
    return (uint)((attr->value).ptr != (char *)0x0);
  }
  iVar1 = sk_num((_STACK *)(attr->value).set);
  return iVar1;
}

