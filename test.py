import deeplake

ds = deeplake.load("hub://activeloop/mura-train")
ds2 = deeplake.load("hub://activeloop/mura-val")

print(ds)
print(ds2)
