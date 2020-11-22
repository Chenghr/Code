import torch
from torch.utils.data import Dataset

class myDataset(Dataset):
    def__init__(self, csv_file, txt_file, root_dir, other_file):