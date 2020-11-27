# __name__属性可以用来识别程序的使用方式
# 每个python脚本作为程序直接运行，__name__属性值被设置成字符串'__main__';
# 脚本作为模块被导入，则__name__属性值被设置成字符串'模块名'

def main():                                     # def是用来定义函数的关键字
    if __name__ == '__main__':                  # 选择结构
        print("This program is run directly.")
    elif __name__ == 'hello':                   # 注意这里的关键字不是 else if，而是 elif
        print("This program used as a model.")
    
main()                                          # 调用上面的函数    