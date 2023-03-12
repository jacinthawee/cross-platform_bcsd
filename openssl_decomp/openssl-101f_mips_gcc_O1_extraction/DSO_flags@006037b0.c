
int DSO_flags(DSO *dso)

{
  if (dso != (DSO *)0x0) {
    return dso->flags;
  }
  return 0;
}

