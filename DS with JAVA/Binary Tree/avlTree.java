class avlTree{
	private class Node{
		int data;
		Node left;
		Node right;
		int height;

		Node(int data){ this.data=data;}
	}

	private Node root;

	public void insert(int data){
		this.root=insertNode(this.root,data);
	}

	private Node insertNode(Node root,int data){
		if(root==null){
			return (new Node(data));
		}
		else if(data>root.data)
			root.right=insertNode(root.right,data);
		else
			root.left=insertNode(root.left,data);
		return root;
	}

	public void display(){
		displayTree(this.root);
	}

	private void displayTree(Node root){
		String str="";
		str+= root.data;
		str+=" (";

		if(root.left!=null) str+=root.left.data;
		str+=" ,";

		if(root.right!=null) str+=root.right.data;
		str+=" )";

		System.out.println(str);

		displayTree(root.left);
		displayTree(root.right);

	}
}